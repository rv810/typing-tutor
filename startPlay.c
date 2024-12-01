#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "type.h"
#define LEVELS 5

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

void drawHand(){

printf("     .--.                   .--. \n");
printf("   __|  |__               __|  |__\n");
printf("  |  |  |  |             |  |  |  |\n");
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

    while (current_level <= LEVELS) {
        displayLevelArt(current_level);
        drawHand();
		if (level(current_level)) {
            progress_bar(current_level, LEVELS);
            current_level += 1;
        }
    }
}
