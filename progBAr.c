#include <stdio.h>
#include <unistd.h> //include statements
/**
 * progress_bar - Displays a textual progress bar.
 *
 * Parameters:
 *  int completed: The current progress or number of completed units.
 *  int total: The total number of units to be completed.
 *
 * Description:
 *  This function displays a progress bar in the terminal, showing the
 *  proportion of completed units relative to the total units. The progress bar
 *  is 70 characters wide by default, with `#` which shows how much of the bar has been filled.
 */

void progress_bar(int completed, int total) {
    int bar_width = 70; //sets width of progress bar
    int progress = (completed * bar_width) / total; //tracks progress

    printf("[");
    for (int i = 0; i < bar_width; ++i) {
        if (i < progress) {
            printf("#"); //prints $ to show how much has been completed
        } else {
            printf(" ");
        }
    }
    printf("] %d%%\r", (completed * 100) / total); //prints out progress bar % of completion
    fflush(stdout);
    printf("\n"); //moves to new line after completing bar
}


