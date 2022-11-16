#include <stdio.h>
#include <stdlib.h>

void illegal_move(int temp){
    printf("%d Illegal move, try again\n",temp);
}

int main()
{
  int iVar1;
  int in_GS_OFFSET;
  int local_28 [6];
  int local_10;
  scanf("%d %d %d %d %d %d", local_28, local_28 + 1, local_28 + 2, local_28 + 3, local_28 + 4, local_28 + 5);
  if (local_28[0] != 1) {
    illegal_move(local_28[0]);
  }
  iVar1 = 1;
  do {
    if (local_28[iVar1] != (iVar1 * iVar1 * iVar1 * iVar1 * 3 + 1 + iVar1 * iVar1 * 5) * iVar1 *  6)
    {
      illegal_move(local_28[iVar1]);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 6);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
}