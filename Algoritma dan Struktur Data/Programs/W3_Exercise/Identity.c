#include <stdio.h>

void identity(char name[], char dob[], char mobile[]){
    printf("Name    : %s\n", name);
    printf("DOB     : %s\n", dob);
    printf("Mobile  : %s\n", mobile);
}
int main()
{
    char name[] = "Ahmad Nadil";
    char dob[] = "November 13, 2003";
    char mobile[] = "081905313210";
    identity(name, dob, mobile);
    return 0;
}