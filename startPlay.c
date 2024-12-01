#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "type.h"
#define LEVELS 5
#define MAX_KEYS_PER_FINGER 6

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

void drawHand(char h [8][MAX_KEYS_PER_FINGER]){
printf("      %c                       %c\n", h[2][5], h[5][5]);
printf("   %c  %c   %c               %c   %c  %c\n", h[1][5], h[2][4], h[3][5], h[4][5], h[5][4], h[6][5]);
printf("   %c  %c   %c               %c   %c  %c\n", h[1][4], h[2][3], h[3][4], h[4][4], h[5][3], h[6][4]);
printf(" %c %c  %c   %c               %c   %c  %c %c\n", h[0][5], h[1][3], h[2][2], h[3][3], h[4][3], h[5][2], h[6][3], h[7][5]);
printf(" %c %c  %c   %c               %c   %c  %c %c\n", h[0][4], h[1][2], h[2][1], h[3][2], h[4][2], h[5][1], h[6][2], h[7][4]);
printf(" %c %c  %c   %c               %c   %c  %c %c\n", h[0][3], h[1][1], h[2][0], h[3][1], h[4][1], h[5][0], h[6][1], h[7][3]);
printf(" %c %c .--. %c               %c .--. %c %c\n", h[0][2], h[1][0], h[3][0], h[4][0], h[6][0], h[7][2]);
printf(" %c __|  |__               __|  |__ %c\n", h[0][1], h[7][1]);
printf(" %c|  |  |  |             |  |  |  |%c\n", h[0][0],h[7][0]);
printf(" _|  |  |  |             |  |  |  |_\n");
printf("| |  |  |  |  __    __   |  |  |  | |\n");
printf("| |  |  |  | /  /  \\  \\  |  |  |  | |\n");
printf("| -     -  |/  /    \\  \\ |  -     - |\n");
printf("|          |  /      \\  \\|          |\n");
printf("|             |      |              |\n");
printf("|            /        \\             |\n");
printf(" \\__________/          \\___________/\n");
}
void startPlay(int argc, char *argv[]) {
    int current_level = 1;

    if (argc == 2) {
        if (strcmp(argv[1], "--help") == 0) {
            help();
            exit(0);
        }
    }
	char test[8][MAX_KEYS_PER_FINGER] = {{'A','Q','Z','X', 'X', 'X'},{'S', 'W', 'X', 'X', 'X', 'X'},{'D', 'E', 'C', 'X', 'X', 'X'},{'F', 'G', 'R', 'T', 'V', 'B'},{'H', 'J', 'Y', 'U', 'N', 'M'},{'K', 'I', 'A', 'A', 'A' , 'A'},{'L', 'O', 'A', 'A', 'A', 'A'},{'P', 'A', 'A', 'A', 'A', 'A'}};
    while (current_level <= LEVELS) {
        displayLevelArt(current_level);
        drawHand(test);
		if (level(current_level)) {
            progress_bar(current_level, LEVELS);
            current_level += 1;
        }
    }
}
