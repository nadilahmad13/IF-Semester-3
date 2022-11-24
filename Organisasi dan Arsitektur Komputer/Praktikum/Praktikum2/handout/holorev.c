#include <stdio.h>
#include <stdlib.h>
#include "support.h"
#include "phases.h"

FILE *infile;

int main(int argc, char *argv[])
{

    char *input;

    if (argc == 1)
    {
        infile = stdin;
    }

    /* Saat dijalankan dengan argumen berupa file, program akan membaca file sampai
    	EOF, kemudian akan membaca dari standar input. Jadi, setiap sudah berhasil menyelesaikan
    	satu level, password untuk memecahkan level tersebut dapat ditaruh ke dalam suatu file
    	dan dapat menghindari untuk mengetik ulang */
    else if (argc == 2)
    {
        if (!(infile = fopen(argv[1], "r")))
        {
            printf("%s: Error: Couldn't open %s\n", argv[0], argv[1]);
            exit(8);
        }
    }

    else
    {
        printf("Usage: %s [<input_file>]\n", argv[0]);
        exit(8);
    }

    start_game();

    printf("Welcome ####, there are 6 stages from this audition that you need to complete to be accepted.\nI'm expecting the best from you!\n");

    input = read_line();
    Uncover_Corps_Basement(input);
    stage_completed();
    printf("You passed the first stage, feeling satisfied?\n");

    input = read_line();
    Holoro(input);
    stage_completed();
    printf("Looks like it's too easy huh? Second round is merely a warm-up.\n");

    input = read_line();
    Holoh3ro(input);
    stage_completed();
    printf("Not bad ###, not bad at all. Let's see if you can decipher the next puzzle.\n");

    input = read_line();
    Secret_Society(input);
    stage_completed();
    printf("Upon meeting the secret society you started to realize something and the key lies on the ##@64#$#\n");

    input = read_line();
    Area15(input);
    stage_completed();
    printf("cGVrb3JhIGJlc3QgZ2lybA==. You started going banana upon learning more facts. Can you really handle the last round?\n");

    input = read_line();
    Green_Necromancer(input);
    stage_completed();
    printf("Omedetou! You passed all the tests and came here on your own\n");
    printf("Nobody is better than you at this. But, now what?\n");
    printf("A strange feeling is lingering inside as if something important is forgotten...\n");

    return 0;
}
