#include <stdio.h>
#include <stdlib.h>

void illegal_move(){
    printf("Illegal move, try again\n");
}


int main()
{
  int iVar1;
  int iVar2;
  int in_GS_OFFSET;
  int local_18;
  int local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  scanf("%d %d",&local_18,&local_14);
//   if (iVar1 < 2) {
//     illegal_move();
//   }
  local_18 = local_18 & 0xf;
  if (local_18 != 0xf) {
    iVar1 = 0;
    iVar2 = 0;
    do {
      iVar2 = iVar2 + 1;
    //   local_18 = *(uint *)(array.3066 + local_18 * 4);
      iVar1 = iVar1 + local_18;
    } while (local_18 != 0xf);
    local_18 = 0xf;
    if ((iVar2 == 0xf) && (local_14 == iVar1)) goto LAB_0001197c;
  }
  illegal_move();
LAB_0001197c:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
//   __stack_chk_fail_local();
}