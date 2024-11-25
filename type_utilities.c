#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define SENTENCES 3
#define LEVELS 5

bool level (int level);
char *generateSentence(int level, int sentence);
float checkAccuracy (char * s);

float sentenceScore (float accuracy, float time) {
        return accuracy + (1 / time);
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
        if (level == 1) {
                if (level_score >= 50) {
                        printf("Congratulations you passed the level!");
                        return true;
                } else {
                        printf("Sorry you didn't pass the level. \n Your score: %f\n Score needed: 50%%\n", level_score);
                        return false;
                }
        }
        if (level == 2) {
                if (level_score >= 60) {
                        printf("Congratulations you passed the level!");
                        return true;
                } else {
                        printf("Sorry you didn't pass the level. \n Your score: %f\n Score needed: 60%%\n", level_score);
                        return false;
                }
        }
        if (level == 3) {
                if (level_score >= 70) {
                        printf("Congratulations you passed the level!");
                        return true;
                } else {
                        printf("Sorry you didn't pass the level. \n Your score: %f\n Score needed: 70%%\n", level_score);
                        return false;
                }
        }
        if (level == 4) {
                if (level_score >= 80) {
                        printf("Congratulations you passed the level!");
                        return true;
                } else {
                        printf("Sorry you didn't pass the level. \n Your score: %f\n Score needed: 80%%\n", level_score);
                        return false;
                }
        }
        if (level == 5) {
                if (level_score >= 90) {
                        printf("Congratulations you passed the level!");
                        return true;
                } else {
                        printf("Sorry you didn't pass the level. \n Your score: %f\n Score needed: 90%%\n", level_score);
                        return false;
                }
        }
}

bool level (int level){
	float accuracy, time_elapsed;
	time_t start, end;
	float sentence_scores[LEVELS];

    	if (sentence_scores == NULL) {
    		printf("Memory allocation failed.\n");
        	return false;
    	}

	for (int i = 1; i <= SENTENCES; i++){
		char *s = generateSentence(level, i);
		time(&start);
		float accuracy = checkAccuracy(s);
		time(&end);
		float time_elapsed = (float)difftime(end, start);
        	sentence_scores[i - 1] = sentenceScore(accuracy, time_elapsed);
		free(s);
	}

	float level_score = levelScore(sentence_scores, LEVELS);
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

	printf("Level %d: Sentence: %d: ", level, sentence);

        for (int i = 0; i < numLines; i++) {
                int randomLine = rand() % count;
                char *word = line[randomLine];
                printf("%s ", word);
                int new_characters = strlen(word) + 1;
                current_characters += new_characters;
                s = realloc(s, sizeof(char)*(current_characters));
                if (s == NULL) {
                        return NULL;
                }
                strcat(s, word);
                strcat(s, " ");
        }
        printf("\n");
        return s;
}


float checkAccuracy (char * s){
	char letter = '\0';
    	int index = 0; //index when comparing iputted string to expected string
    	int correct_letters = 0; // total number of CORRECT letters the user typed
    	int total_letters = 0; //length of string the user is supposed to type
    	printf("Please type sentence here: ");

    	//finding length of string
    	while (s[total_letters] != '\0'){
        	total_letters +=1;
    	}

    	while (index<total_letters && letter != '\n'){
        	scanf("%c", &letter);

        	if (letter == s[index]){
                	correct_letters +=1;
                	index +=1;
       	 	}
    	}

    	float accuracy = correct_letters/(float)total_letters;

    	return accuracy;
}

