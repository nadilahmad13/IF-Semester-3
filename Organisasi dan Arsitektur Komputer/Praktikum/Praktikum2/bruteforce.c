#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

int func4(int param_1,int param_2)

{
  if (param_2 < param_1) {
    param_2 = func4(param_2,param_1);
  }
  else if (param_1 != 0) {
    param_2 = func4(param_2 % param_1,param_1);
  }
  return param_2;
}

int main()
{
    int x = 0;
    int y = 0;
    int iVar1;
    boolean found = false;

    while(!found){
        printf("%d %d\n",x,y);
        iVar1 = func4(x,y);
        if ((x * y) / iVar1 == 0x78){
            printf("%d %d\n",x,y);
            found = true;
        }

        if(x == 0x75){
            x = 0;
            y++;
        }
        else{
            x++;
        }
        printf("%d %d\n",x,y);
    }
}