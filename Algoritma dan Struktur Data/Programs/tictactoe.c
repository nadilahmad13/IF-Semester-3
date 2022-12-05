#include <stdio.h>
#include <stdlib.h>

int checkwin(int board[3][3]){
    // X win
    if (board[0][0] == 1 && board[0][1] == 1 && board[0][2] == 1) return 1;
    if (board[1][0] == 1 && board[1][1] == 1 && board[1][2] == 1) return 1;
    if (board[2][0] == 1 && board[2][1] == 1 && board[2][2] == 1) return 1;
    if (board[0][0] == 1 && board[1][0] == 1 && board[2][0] == 1) return 1;
    if (board[0][1] == 1 && board[1][1] == 1 && board[2][1] == 1) return 1;
    if (board[0][2] == 1 && board[1][2] == 1 && board[2][2] == 1) return 1;
    if (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1) return 1;
    if (board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1) return 1;
    // O win
    if (board[0][0] == 2 && board[0][1] == 2 && board[0][2] == 2) return 2;
    if (board[1][0] == 2 && board[1][1] == 2 && board[1][2] == 2) return 2;
    if (board[2][0] == 2 && board[2][1] == 2 && board[2][2] == 2) return 2;
    if (board[0][0] == 2 && board[1][0] == 2 && board[2][0] == 2) return 2;
    if (board[0][1] == 2 && board[1][1] == 2 && board[2][1] == 2) return 2;
    if (board[0][2] == 2 && board[1][2] == 2 && board[2][2] == 2) return 2;
    if (board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2) return 2;
    if (board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 2) return 2;
    // draw
    return 0;
}

int printBoard(int board[3][3]){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if (board[i][j] == 0){
                printf(".");
            }
            else if (board[i][j] == 1){
                printf("X");
            }
            else if (board[i][j] == 2){
                printf("O");
            }
            if (j != 2){
                printf(" ");
            }
        }
        printf("\n");
    }
}

int playervplayer(){
        // create a 3x3 array of integers
    int board[3][3];

    // initialize the board to all 0's
    int i,j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            board[i][j] = 0;
        }
    }
    // draw the board
    printBoard(board); 

    // variable initialization
    int row, col;
    int endgame = 0;
    int playerTurn = 1;
    int count = 0;
    // main game loop
    while(endgame == 0){
        printf("Player%d your move: ", playerTurn);
        scanf("%d %d", &row, &col);

        // Player 1 is X, Player 2 is O

        // check if row and col input is valid
        if (row >= 0 && row <= 2 && col >= 0 && col <= 2){
            // Player 1's turn
            if (playerTurn == 1 && board[row][col] == 0){
                board[row][col] = 1;
                playerTurn = 2;
                count ++;
                printBoard(board);
            }

            // Player 2's turn
            else if (playerTurn == 2){
                board[row][col] = 2;
                playerTurn = 1;
                count ++;
                printBoard(board);
            }
        }

        // Win condition check
        if (checkwin(board) == 1){
            printf("Player1 wins.\n");
            endgame = 1;
        }
        else if (checkwin(board) == 2){
            printf("Player2 wins.\n");
            endgame = 1;
        }
        else if (count == 9){
            printf("Draw.\n");
            endgame = 1;
        }
    }

    // press enter to continue
    printf("Press enter to continue... ");
    int temp;
    scanf("%d", &temp);

    return 0;
}

int minimax(int board[3][3]){
    int move = -1;
    int score = -2;
    int i,j;
    for(i = 0; i < 3 ; i++){
        for(j = 0; j < 3; j++){
            if (board[i][j] == 0){
                board[i][j] = 2;
                int tempScore = -minimax(board);
                if (tempScore > score){
                    score = tempScore;
                    move = i*3+j;
                }
                board[i][j] = 0;
            }
        }
    }
    if (move == -1) return 0;
    return score;
}


int playervbot(){
    // create a 3x3 array of integers
    int board[3][3];

    // initialize the board to all 0's
    int i,j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            board[i][j] = 0;
        }
    }
    // draw the board
    printBoard(board); 

    // variable initialization
    int row, col;
    int endgame = 0;
    int playerTurn = 1;
    int count = 0;
    // main game loop
    while(endgame == 0){
        if (playerTurn == 1){
            printf("Player1 your move: ");
            scanf("%d %d", &row, &col);
        }
        else if (playerTurn == 2){
            printf("Bot's move: \n");
            int move = -1;
            int score = -2;
            int i,j;
            for(i = 0; i < 3 ; i++){
                for(j = 0; j < 3; j++){
                    if (board[i][j] == 0){
                        board[i][j] = 2;
                        int tempScore = -minimax(board);
                        if (tempScore > score){
                            score = tempScore;
                            move = i*3+j;
                        }
                        board[i][j] = 0;
                    }
                }
            }
            row = move/3;
            col = move%3;
        }

        // Player 1 is X, Player 2 is O

        // check if row and col input is valid
        if (row >= 0 && row <= 2 && col >= 0 && col <= 2){
            // Player 1's turn
            if (playerTurn == 1 && board[row][col] == 0){
                board[row][col] = 1;
                playerTurn = 2;
                count ++;
                printBoard(board);
            }

            // Player 2's turn
            else if (playerTurn == 2){
                board[row][col] = 2;
                playerTurn = 1;
                count ++;
                printBoard(board);
            }
        }

        // Win condition check
        if (checkwin(board) == 1){
            printf("Player1 wins.\n");
            endgame = 1;
        }
        else if (checkwin(board) == 2){
            printf("Bot wins.\n");
            endgame = 1;
        }
        else if (count == 9){
            printf("Draw.\n");
            endgame = 1;
        }
    }

    // press enter to continue
    printf("Press enter to continue... ");
    getchar();

    return 0;
}

int main(){
    int gameMode;
    int loop = 1;
    while(loop == 1){
        printf("\033[2J\033[1;1H");
        printf("Welcome to Tic Tac Toe!\n");
        printf("1. Player vs Player\n");
        printf("2. Player vs Computer\n");
        printf("3. Exit\n");
        printf("Select game mode: ");
        scanf("%d", &gameMode);
        if (gameMode == 1){
            playervplayer();
        }
        else if (gameMode == 2){
            playervbot();
        }
        else if (gameMode == 3){
            loop = 0;
        }
        else{
            printf("Invalid input.\n");
        }
    }
}