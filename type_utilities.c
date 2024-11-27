#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define SENTENCES 3
#define LEVELS 5
#define BASE_SCORE 50
#define DEBUG 0
bool level (int level);
char *generateSentence(int level, int sentence);
float checkAccuracy (char * s);

void help() {
    printf("KEYBOARD WARRIOR (Version v1.0.0)\n\n");
    printf("Usage: type \n\n");

    printf("Description:\n");
    printf("  Keyboard Warrior is a typing tutor designed for kids to improve their typing skills.\n");
    printf("  The program includes multiple levels, tracks accuracy and typing speed, and provides\n");
    printf("  feedback to indicate whether the user passed or failed a level.\n\n");

    printf("Arguments:\n");
    printf("  None\n\n");
    
    printf("Flags:\n");
    printf("  --help                Display this help message and exit.\n\n");

    printf("Pass Criteria:\n");
    printf("  Level 1: 50%%\n");
    printf("  Level 2: 55%%\n");
    printf("  Level 3: 60%%\n");
    printf("  Level 4: 65%%\n");
    printf("  Level 5: 70%%\n\n");

    printf("Examples:\n");
    printf("  type \n");
    printf("    Start the program from Level 1.\n\n");
    printf("  type --help\n");
    printf("    Display this help message.\n\n");
}

float sentenceScore (float accuracy, float time) {
        float accuracy_weight = 0.8;
        float time_weight = 0.2;
		if (time <= 0) {
        	return 0; 
    	}

    	return (accuracy_weight * accuracy) + (time_weight * (1 / time));
}

float levelScore (float scores[], int size) {
        float sum = 0.0;
        for (int i=0; i<size; i++) {
                sum += scores[i];
        }
        float percentage_score = (sum/size)*100;
        return percentage_score;
}

bool isPass(int level, float level_score) {
        int score_required = BASE_SCORE+(5*(level-1));
		if (level_score >= score_required) {
                printf("\nCongratulations you passed the level!\n\n");
                return true;
		} else {
			printf("\nSorry you didn't pass the level.\nYour score: %.2f%%\nScore needed: %i%%\n\n", level_score, score_required);
			return false;
        }
}

bool level (int level){
	float accuracy, time_elapsed;
	time_t start, end;
	float sentence_scores[SENTENCES];

   	if (sentence_scores == NULL) {
   		printf("Memory allocation failed.\n");
       	return false;
   	}

	for (int i = 1; i <= SENTENCES; i++){
		char *s = generateSentence(level, i);
		time(&start);
		accuracy = checkAccuracy(s);
		time(&end);
		time_elapsed = (float)difftime(end, start);
                
		if (DEBUG == 1){
			printf("accuracy: %f%%\n", accuracy);
			printf("time: %fs\n", time_elapsed);
        }
		sentence_scores[i - 1] = sentenceScore(accuracy, time_elapsed);
		free(s);
	}

	float level_score = levelScore(sentence_scores, SENTENCES);
        bool is_pass = isPass(level, level_score);
        return is_pass;
}

char *generateSentence(int level, int sentence) {
        int numLines = 7;
        FILE *file;
        if (level == 1) {
                file = fopen("level1.txt", "r");
        } else if (level == 2) {
                file = fopen("level2.txt", "r");
        } else if (level == 3) {
                file = fopen("level3.txt", "r");
        } else if (level == 4) {
                file = fopen("level4.txt", "r");
        } else if (level == 5) {
                file = fopen("level5.txt", "r");
        }

        char line[100][10000];
        int count = 0;

        while (fgets(line[count], sizeof(line[0]), file) != NULL) {
                line[count][strcspn(line[count], "\n")] = '\0';
                count++;
        }

        fclose(file);
        int current_characters = 1;
        char *s = malloc(sizeof(char)*current_characters);
        if (s == NULL) {
                return NULL;
        }
        s[0] = '\0';

	printf("Level %d, Sentence: %d: ", level, sentence);

        for (int i = 0; i < numLines; i++) {
                int randomLine = rand() % count;
                char *word = line[randomLine];
                int new_characters = strlen(word) + 1;
                current_characters += new_characters;
                s = realloc(s, sizeof(char)*(current_characters));
                if (s == NULL) {
                        return NULL;
                }
                strcat(s, word);
                if(i != numLines-1){
					strcat(s, " ");
				}
				else{
					strcat(s, ".");
				}	
        }
		printf("%s\n", s);
        return s;
}


float checkAccuracy (char * s){
	char letter = 'a';
	char temp = 'a';
	int index = 0; //index when comparing iputted string to expected string
    int correct_letters = 0; // total number of CORRECT letters the user typed
    int total_letters = 0; //length of string the user is supposed to type
    printf("Please type sentence here: ");

		//finding length of string
    while (s[total_letters] != '\0'){
       	total_letters +=1;
    }

    while (index<total_letters){
		scanf("%c", &letter);
		if (letter == '.'){
			correct_letters +=1;
			break;
		}

		if (letter == s[index]){
    		correct_letters +=1;
            index +=1;
		}
    }

    float accuracy = correct_letters/(float)total_letters;

    return accuracy;
}

