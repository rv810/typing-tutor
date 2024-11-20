#include <stdio.h>
#include <unistd.h>

void progress_bar(int completed, int total) {
    int bar_width = 70;
    int progress = (completed * bar_width) / total;

    printf("[");
    for (int i = 0; i < bar_width; ++i) {
        if (i < progress) {
            printf("#");
        } else {
            printf(" ");
        }
    }
    printf("] %d%%\r", (completed * 100) / total);
    fflush(stdout);
    printf("\n"); 
}


