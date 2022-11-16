#include <stdio.h>
#include <stdlib.h>

int func4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((0 < param_1) && (iVar2 = param_2, param_1 != 1)) {
    iVar1 = func4(param_1 + -1,param_2);
    iVar2 = func4(param_1 + -2,param_2);
    iVar2 = iVar2 + iVar1 + param_2;
  }
  return iVar2;
}

void illegal_move(){
    printf("Illegal move, try again\n");
}

int main(){
{
  int iVar1;
  int in_GS_OFFSET;
  int local_18;
  int local_14;
  int local_10;
  
//   local_10 = *(int *)(in_GS_OFFSET + 0x14);
  scanf("%d %d",&local_14,&local_18);
  if ((2 < local_18 - 2U)) {
    illegal_move();
  }
  iVar1 = func4(6,local_18);
  printf("%d",iVar1);
  if (local_14 != iVar1) {
    illegal_move();
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
//   __stack_chk_fail_local();
}

}

