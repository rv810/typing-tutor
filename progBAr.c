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

void countdown_timer(int seconds) {
    for (int elapsed = 0; elapsed <= seconds; ++elapsed) {
        progress_bar(elapsed, seconds);
        sleep(1); 
    }
}

int main() {
    
    int predefined_seconds = 10; //change this to level, time, etc. (i think level for us)
    
    countdown_timer(predefined_seconds);

    return 0;
}

