#include <stdio.h>
#include "jumlahkonsonanvokal.h"

#define boolean int
#define true 1
#define false 0

boolean isAlphabet(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

boolean isVowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

void jumlahKonsonanVokal(char *s, int *konsonan, int *vokal) {
    int i = 0;
    while (s[i] != '\0') {
        if (isAlphabet(s[i])) {
            if (isVowel(s[i])) {
                (*vokal)++;
            } else {
                (*konsonan)++;
            }
        }
        i++;
    }
}

int main(){
    char kalimat[100];
    int konsonan = 0;
    int vokal = 0;
    printf("Masukkan kalimat: ");
    gets(kalimat);
    printf("Kalimat: %s\n", kalimat);
    jumlahKonsonanVokal(kalimat, &konsonan, &vokal);
    printf("Jumlah konsonan: %d\n" , konsonan);
    printf("Jumlah vokal: %d\n" , vokal);
    return 0;
}