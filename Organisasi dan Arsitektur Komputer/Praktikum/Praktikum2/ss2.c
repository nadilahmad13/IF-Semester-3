#include <stdio.h>
#include <stdlib.h>

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

void illegal_move(){
    printf("Illegal move, try again\n");
}

int main()

{
  int iVar1;
  int in_GS_OFFSET;
  int local_18;
  int local_14;
  int local_10;
  
//   local_10 = *(int *)(in_GS_OFFSET + 0x14);
  scanf("%d %d",&local_14,&local_18);
  if ((0x75 < local_18 - 2U) || (0x75 < local_14 - 2U)) {
    illegal_move();
    printf("kena 1\n");
  }
  iVar1 = func4(local_18,local_14);
  printf("%d\n",iVar1);
  printf("%d\n",((local_14 * local_18) / iVar1));
  if ((local_14 * local_18) / iVar1 != 0x78) {
    illegal_move();
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
}