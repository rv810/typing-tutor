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
}

void prog_level(int levels) {
    int total_steps = levels * 1; 
    for (int step = 0; step <= total_steps; ++step) {
        progress_bar(step, total_steps);
        sleep(1); 
    }
    printf("\n"); 
}
