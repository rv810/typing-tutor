#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

	char line[50][10000];
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

int main() {
	srand(time(NULL));
	generateSentence(1, 1);
	generateSentence(1, 2);
	generateSentence(1, 3);
}
