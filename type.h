#include <stdbool.h>
void help();
bool level (int level);
void progress_bar(int completed, int total);
void startPlay();

//included for the test_main
float checkAccuracy (char * s);
float sentenceScore (float accuracy, float time);
float levelScore (float scores[], int size);
bool isPass(int level, float level_score);