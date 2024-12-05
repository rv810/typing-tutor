#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "type.h"
#define LEVELS 5
#define MAX_KEYS_PER_FINGER 6
#define FINGERS 8

/* displayLevelArt
 *
 * Parameters:
 * - level: the current level number to display.
 *
 * Description: Displays ASCII art for the current level, including the level number,
 *              to provide a visual representation of progress in the game.
 *
 * Return: None.
 */
void displayLevelArt(int level) {
    printf("\n");
    printf(" __       ___________    ____  _______  __      \n");
    printf("|  |     |   ____\\   \\  /   / |   ____||  |     \n");
    printf("|  |     |  |__   \\   \\/   /  |  |__   |  |     \n");
    printf("|  |     |   __|   \\      /   |   __|  |  |     \n");
    printf("|  `----.|  |____   \\    /    |  |____ |  `----.\n");
    printf("|_______||_______|   \\__/     |_______||_______|\n");
    printf("                                                \n");
    printf("                      LEVEL %d                   \n", level);
    printf("\n");
}

/* drawHand
 *
 * Parameters:
 * - h: a 2D array of characters representing keys assigned to each finger on the keyboard.
 *
 * Description: Prints a visual representation of a keyboard and hand positions,
 *              with specific keys highlighted based on the input array.
 *
 * Return: None.
 */
void drawHand(char h [FINGERS][MAX_KEYS_PER_FINGER]){
    printf("      %c                       %c\n", h[2][5], h[5][5]);
    printf("   %c  %c   %c               %c   %c  %c\n", h[1][5], h[2][4], h[3][5], h[4][5], h[5][4], h[6][5]);
    printf("   %c  %c   %c               %c   %c  %c\n", h[1][4], h[2][3], h[3][4], h[4][4], h[5][3], h[6][4]);
    printf(" %c %c  %c   %c               %c   %c  %c %c\n", h[0][5], h[1][3], h[2][2], h[3][3], h[4][3], h[5][2], h[6][3], h[7][5]);
    printf(" %c %c  %c   %c               %c   %c  %c %c\n", h[0][4], h[1][2], h[2][1], h[3][2], h[4][2], h[5][1], h[6][2], h[7][4]);
    printf(" %c %c  %c   %c               %c   %c  %c %c\n", h[0][3], h[1][1], h[2][0], h[3][1], h[4][1], h[5][0], h[6][1], h[7][3]);
    printf(" %c %c .--. %c               %c .--. %c %c\n", h[0][2], h[1][0], h[3][0], h[4][0], h[6][0], h[7][2]);
    printf(" %c __|  |__               __|  |__ %c\n", h[0][1], h[7][1]);
    printf(" %c|  |  |  |             |  |  |  |%c\n", h[0][0],h[7][0]);
    printf(" _|  |  |  |    SPACE    |  |  |  |_\n");
    printf("| |  |  |  |  __    __   |  |  |  | |\n");
    printf("| |  |  |  | /  /  \\  \\  |  |  |  | |\n");
    printf("| -     -  |/  /    \\  \\ |  -     - |\n");
    printf("|          |  /      \\  \\|          |\n");
    printf("|             |      |              |\n");
    printf("|            /        \\             |\n");
    printf(" \\__________/          \\___________/\n");
}


/* startPlay
 *
 * Parameters:
 * - argc: the number of command-line arguments.
 * - argv: an array of strings representing the command-line arguments.
 *
 * Description: Starts the typing game by displaying level-specific ASCII art
 *              and drawing keyboard hand positions. Levels progress as the user
 *              completes them. The user can exit the game early by responding with 'N'
 *              when prompted.
 *
 * Return: None.
 */
void startPlay(int argc, char *argv[]) {
    int current_level = 1;
    char continue_play;
	char keys[FINGERS][MAX_KEYS_PER_FINGER] = {{' ',' ',' ',' ', ' ', ' '},{' ', ' ', ' ', ' ', ' ', ' '},{' ', ' ', ' ', ' ', ' ', ' '},{' ', ' ', ' ', ' ', ' ', ' '},{' ', ' ', ' ', ' ', ' ', ' '},{' ', ' ', ' ', ' ', ' ' , ' '},{' ', ' ', ' ', ' ', ' ', ' '},{' ', ' ', ' ', ' ', ' ', ' '}};


    if (argc == 2) {
        if (strcmp(argv[1], "--help") == 0) {
            int help_status = help();
            exit(0);
        }
    }

	while (current_level <= LEVELS) {
        displayLevelArt(current_level);
        if (current_level == 1){
            keys[0][0] = 'A';
            keys[1][0] = 'S';
            keys[2][0] = 'D';
            keys[4][0] = 'J';
            keys[5][0] = 'K';
            keys[6][0] = 'L';
	    }
        else if (current_level == 2){
            keys[3][0] = 'R';
            keys[3][1] = 'T';
            keys[4][1] = 'Y';
            keys[4][2] = 'U';
        }
        else if (current_level == 3){
            keys[0][1] = 'Q';
            keys[1][1] = 'W'; 
            keys[2][1] = 'E';
            keys[5][1] = 'I';
            keys[6][1] = 'O';
            keys[7][0] = 'P';
	    }
        else if (current_level == 4){
            keys[0][2] = 'Z';
            keys[1][2] = 'X';
            keys[4][3] = 'N';
            keys[4][4] = 'M';
        }
        else{
            keys[2][2] = 'C';
            keys[3][2] = 'V';
            keys[3][3] = 'B';
            keys[3][4] = 'F';
            keys[3][5] = 'G';
            keys[4][5] = 'H';
        }
        drawHand(keys);

		if (level(current_level)) {
            progress_bar(current_level, LEVELS);
            current_level += 1;
        }

        printf("\nWould you like to continue playing (Y/N)? ");
        scanf(" %c", &continue_play);

        if (continue_play == 'N' || continue_play == 'n') {
            printf("See you later!\n\n");
            exit(0);
        }
    }
}
