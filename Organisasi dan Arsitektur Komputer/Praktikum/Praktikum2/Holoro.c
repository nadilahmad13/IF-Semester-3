#include <stdio.h>
#include <stdlib.h>


void illegal_move(int temp){
    printf("%d Illegal move, try again\n",temp);
}

void illegal_move(){
    printf("Illegal move, try again\n");
}


int main(){
    unsigned int uVar1;
    int aiStack_2c[7];
    int local_10;
    int i;
    // read six numbers
    scanf("%d %d %d %d %d %d", aiStack_2c + 1, aiStack_2c + 2, aiStack_2c + 3, aiStack_2c + 4, aiStack_2c + 5, aiStack_2c + 6);
    if (aiStack_2c[1] != 1){
        illegal_move(aiStack_2c[1]);
    }
    uVar1 = 1;

  do {
        if ((uVar1 & 1) == 0) {
        if (aiStack_2c[uVar1 + 1] != uVar1 * aiStack_2c[uVar1]) goto LAB_0001172e;
        }
        else if (aiStack_2c[uVar1 + 1] != uVar1 + aiStack_2c[uVar1]) {
    LAB_0001172e:
        illegal_move(aiStack_2c[uVar1 + 1]);
        }
        uVar1 = uVar1 + 1;
        if (uVar1 == 6) {
        // if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
        //                 /* WARNING: Subroutine does not return */
        //     __stack_chk_fail_local();
        // }
        return;
        }
    } while( 1 );
}