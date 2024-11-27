#include <stdio.h>
#include <stdlib.h>
#include "type.h"

int main() {

    //testing checkAccuracy
    // run "cat accuracy_correct.txt | ./ctest OR cat accuracy_incorrect.txt" to check
    char * s = "sample string";
    int accuracy = checkAccuracy(s);
    if (accuracy == 1){
        printf("\ncorrect output for accuracy\n");
    }
    else{
        printf("\nincorrect output for accuracy\n");
    }
}

