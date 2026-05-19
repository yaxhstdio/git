#include <stdio.h>

int main() {
    int pages[] = {1,2,3,4,1,2,5,1,2,3,4,5};
    int n = 12, frames = 3;
    int frame[3], time[3];
    int faults = 0, counter = 0;

    for (int i = 0; i < frames; i++)
        frame[i] = -1;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }

        if (!found) {
            int pos = 0;
            for (int j = 1; j < frames; j++)
                if (time[j] < time[pos])
                    pos = j;

            frame[pos] = pages[i];
            counter++;
            time[pos] = counter;
            faults++;
        }
    }

    printf("Total Page Faults = %d\n", faults);
    return 0;
}