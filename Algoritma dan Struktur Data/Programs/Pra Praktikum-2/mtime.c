#include <stdio.h>
#include "time.c"

int main(){
    int N,i;
    long diff;
    scanf("%d", &N);
    TIME start,end,temp,minStart,maxStart;
    CreateTime(&maxStart, 0, 0, 0);
    CreateTime(&minStart, 23, 59, 59);
    for (i = 0 ; i < N ; i++){
        printf("[%d]\n", i+1);
        BacaTIME(&start);
        BacaTIME(&end);
        if (TIMEToDetik(start) > TIMEToDetik(end)){
            temp = start;
            start = end;
            end = temp;
        }
        diff = Durasi(start, end);
        printf("%ld\n", diff);

        if (TIMEToDetik(start) < TIMEToDetik(minStart)){
            minStart = start;
        }
        if (TIMEToDetik(start) > TIMEToDetik(maxStart)){
            maxStart = start;
        }
        if (TIMEToDetik(end) < TIMEToDetik(minStart)){
            minStart = end;
        }
        if (TIMEToDetik(end) > TIMEToDetik(maxStart)){
            maxStart = end;
        }
    }
    TulisTIME(minStart);
    printf("\n");
    TulisTIME(maxStart);
    printf("\n");

    return 0;
}