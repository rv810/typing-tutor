#include <stdio.h>
#include <time.h>
#include <unistd.h> // For sleep() on Unix/Linux systems

// Function to simulate a countdown timer
void countdown_timer(int seconds) {

    for (int remaining = seconds; remaining > 0; --remaining) {
        printf(" %d seconds\n", remaining);
        sleep(1); // Pause for 1 second
    }
}

int main() {
    int predefined_seconds = 10; // Set the timer for 10 seconds

    // Call the countdown timer function
    countdown_timer(predefined_seconds);

    return 0;
}

