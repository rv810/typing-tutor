#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "type.h"

/* main
 *
 * Parameters:
 * - argc: the number of command-line arguments passed to the program
 * - argv: an array of strings representing the command-line arguments
 *
 * Description: Tests various functions in the program, including `checkAccuracy`,
 *              `progress_bar`, `sentenceScore`, and `help`. It verifies expected
 *              and actual outputs, printing the results for validation.
 *
 * Return: 0 for successful execution.
 */
int main (int argc, char *argv[]){
    // Testing checkAccuracy
    // run "cat accuracy_correct.txt | ./ctest" OR "cat accuracy_incorrect.txt" to check
    char *s = "sample string";
    int accuracy = checkAccuracy(s);
    if (accuracy == 1) {
        printf("\nCorrect output for accuracy\n");
    } else {
        printf("\nIncorrect output for accuracy\n");
    }

    // Testing progress bar
    printf("\n--- Testing Progress Bar ---\n");

    printf("\nTest Case 1: Progress at 0%%\n");
    printf("Expected output: [                                                                      ] 0%%\n");
    printf("Actual output:   ");
    progress_bar(0, 100);
    printf("\nProgress bar test for 0%% completed.\n");

    printf("\nTest Case 2: Progress at 50%%\n");
    printf("Expected output: [#####################################                                 ] 50%%\n");
    printf("Actual output:   ");
    progress_bar(50, 100);
    printf("\nProgress bar test for 50%% completed.\n");

    // Testing score functions
    printf("\n--- Testing Sentence Scores ---\n");

    printf("\nTest Case 1: Accuracy = 0.9, Time = 2.0\n");
    float score1 = sentenceScore(0.9, 2.0);
    printf("Expected: ~0.74, Actual: %.2f\n", score1);

    printf("\nTest Case 2: Accuracy = 0.5, Time = 1.0\n");
    float score2 = sentenceScore(0.5, 1.0);
    printf("Expected: ~0.6, Actual: %.2f\n", score2);

    printf("\n--- Testing Overall Level Score ---\n");

    printf("\nTest Case 1: Scores = {50.0, 67.0, 80.0, 75.0, 24.0}, Size = 5\n");
    float scores[] = {50.0, 67.0, 80.0, 75.0, 24.0};
    float level_score = levelScore(scores, 5);
    printf("Expected: ~0.74, Actual: %.2f\n", level_score);

    //Testing pass/fail check
    printf("\n--- Testing Pass/Fail Check ---\n");
    printf("(Returns 1 for true and 0 for false)\n");
    
    printf("\nTest Case 1: Level = 3, Score = 70.0\n");
    bool checkPass1 = isPass(3, 70.0);
    printf("Expected: 1, Actual: %d\n", checkPass1);

    printf("\nTest Case 2: Level = 5, Score = 40.0\n");
    bool checkPass2 = isPass(5, 40.0);
    printf("Expected: 0, Actual: %d\n", checkPass2);

    //Testing help function
    printf("\n--- Testing Help Functionality ---\n");
    int help_status = help();
    if (help_status != 0) {
        printf("Help functionality failed!");
    }
    printf("Help functionality test successful!\n");

    //Testing generate sentence function
    printf("\n--- Testing Sentence Generation ---\n");
    int used[100] = {0}; 
    int foundWords = 0;  
    int totalWords = 15;
    int sentenceNum = 0; 
    char *wordList[] = {"skl", "kasd", "sall", "dlk", "jsal", "jalk", "laasd", "sakk", "jadls", "skj", "asda", "klasd", "dkk", "lad", "jlja"};

    while (foundWords < totalWords) {
    	char *sentence = generateSentence(1, ++sentenceNum);

    	for (int i = 0; i < totalWords; i++) {
        	if (!used[i] && strstr(sentence, wordList[i])) {
            	used[i] = 1;
            	foundWords++;
            	printf("Found: %s\n", wordList[i]);
        	}
    	}
    	free(sentence);
    }
    printf("\nAll words returned!\n");

    int used2[100] = {0};
    foundWords = 0;
    totalWords = 15;
    sentenceNum = 0;
    char *wordList2[] = {"dkalsk", "stytl", "suyt", "tulj", "start", "klrty", "drua", "rat", "lutt", "klta", "yuls", "ulda", "jrty", "salt", "luks"};

    while (foundWords < totalWords) {
        char *sentence = generateSentence(2, ++sentenceNum);

        for (int i = 0; i < totalWords; i++) {
                if (!used2[i] && strstr(sentence, wordList2[i])) {
                used2[i] = 1;
                foundWords++;
                printf("Found: %s\n", wordList2[i]);
                }
        }
        free(sentence);
    }
    printf("\nAll words returned!\n");

    int used3[100] = {0};
    foundWords = 0;
    totalWords = 15;
    sentenceNum = 0;
    char *wordList3[] = {"were", "dart", "lots", "sport", "lease", "pleased", "work", "pots", "quest", "litter", "poster", "wasp", "play", "warp", "loop"};

    while (foundWords < totalWords) {
        char *sentence = generateSentence(3, ++sentenceNum);

        for (int i = 0; i < totalWords; i++) {
                if (!used3[i] && strstr(sentence, wordList3[i])) {
                used3[i] = 1;
                foundWords++;
                printf("Found: %s\n", wordList3[i]);
                }
        }
        free(sentence);
    }
    printf("\nAll words returned!\n");

    int used4[100] = {0};
    foundWords = 0;
    totalWords = 15;
    sentenceNum = 0;
    char *wordList4[] = {"mop", "sandy", "mozzarella", "ponder", "money", "went", "wax", "lemon", "jinxed", "jumped", "quizzes", "enzymes", "equinox", "squeaky", "jeopardy"};

    while (foundWords < totalWords) {
        char *sentence = generateSentence(4, ++sentenceNum);

        for (int i = 0; i < totalWords; i++) {
                if (!used4[i] && strstr(sentence, wordList4[i])) {
                used4[i] = 1;
                foundWords++;
                printf("Found: %s\n", wordList4[i]);
                }
        }
        free(sentence);
    }
    printf("\nAll words returned!\n");

    int used5[100] = {0};
    foundWords = 0;
    totalWords = 15;
    sentenceNum = 0;
    char *wordList5[] = {"daughter", "extravagent", "popular", "mayonaise", "questionable", "outnumbered", "devastating", "technology", "resolution", "requirements", "patience", "software", "management", "saturday", "tremendous"};

    while (foundWords < totalWords) {
        char *sentence = generateSentence(5, ++sentenceNum);

        for (int i = 0; i < totalWords; i++) {
                if (!used5[i] && strstr(sentence, wordList5[i])) {
                used5[i] = 1;
                foundWords++;
                printf("Found: %s\n", wordList5[i]);
                }
        }
        free(sentence);
    }
    printf("\nAll words returned!\n");
    printf("All words successfully printed for all levels\n");
    return 0;
}
