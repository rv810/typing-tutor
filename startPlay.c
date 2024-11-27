#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "type.h"
#define LEVELS 5

void startPlay(){
	int current_level = 1;

	if (argc == 2) {
		if (strcmp(argv[1], "--help") == 0) {
            help();
            exit(0);
        }
	}
	
	while (current_level <= 5){
		if (level(current_level)){
			progress_bar(current_level, LEVELS);
			current_level+=1;
		}
	}
}
