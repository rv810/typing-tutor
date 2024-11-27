#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "type.h"

int main (int argc, char *argv[]){
    if (argc == 2) {
		if (strcmp(argv[1], "--help") == 0) {
            help();
            exit(0);
        }
	}
    
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

    return 0;
}

