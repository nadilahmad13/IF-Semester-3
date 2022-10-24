#include "stack.c"
#include "boolean.h"
#include "string.h"
#include "stdlib.h"

boolean isOperator(char input)
/* Proses: Mengecek apakah input merupakan operator */
/*         input adalah operator jika input merupakan salah
           satu dari berikut:
                - +
                - -
                - *
                - /
*/
{
    return (input == '+' || input == '-' || input == '*' || input == '/');
}

int hitung(int angka1, int angka2, char op)
/* Proses: Menghitung ekspresi */
/*
    Contoh input / output:
    angka1 : 2
    angka2 : 10
    op     : -

    return : -8 (penjelasan: 2 - 10 = 8)
*/
{
    if (op == '+')
        return angka1 + angka2;
    else if (op == '-')
        return angka1 - angka2;
    else if (op == '*')
        return angka1 * angka2;
    else if (op == '/')
        return angka1 / angka2;
}

int eval(char *input, int length)
/* Proses: Menghitung keseluruhan ekspresi */
/* I.S. input adalah string. setiap operand dipastikan < 10 */
/*
    Contoh input / output:
    input   : 23+
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 2 + 3)

    input   : 9423+*5/-
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 9-(4*(2+3))/5)

*/
{
    Stack S;
    CreateEmpty(&S);
    int i;
    for (i = 0; i < length; i++)
    {
        if (isOperator(input[i]))
        {
            int angka2 = InfoTop(S);
            Pop(&S, &angka2);
            int angka1 = InfoTop(S);
            Pop(&S, &angka1);
            int hasil = hitung(angka1, angka2, input[i]);
            Push(&S, hasil);
        }
        else
        {
            Push(&S, input[i] - 48);
        }
    }
    return InfoTop(S);
}

int main()
{
    int n;
    n = eval("23+", 3);
    printf("%d\n", n);

    n = eval("9423+*5/-", 9);
    printf("%d\n", n);

    n = eval("45*39*13+/+", 10);
    printf("%d\n", n);
    return 0;
}