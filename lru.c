#include <stdio.h>

int main() {
    int pages[50], frame[10], time[10];
    int n, frames;
    int i, j, k, pageFaults = 0, found, pos, least;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frames);
    for (i = 0; i < frames; i++) {
        frame[i] = -1;
        time[i] = 0;
    }
    printf("\nPage\tFrames\n");

    for (i = 0; i < n; i++) {
        found = 0;
        for (j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                time[j] = i + 1;
                break;
            }
        }


        if (!found) {

            for (j = 0; j < frames; j++) {
                if (frame[j] == -1) {
                    frame[j] = pages[i];
                    time[j] = i + 1;
                    pageFaults++;
                    goto display;
                }
            }
            least = time[0];
            pos = 0;
            for (j = 1; j < frames; j++) {
                if (time[j] < least) {
                    least = time[j];
                    pos = j;
                }
            }

            frame[pos] = pages[i];
            time[pos] = i + 1;
            pageFaults++;
        }

display:
        printf("%d\t", pages[i]);
        for (j = 0; j < frames; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);
    return 0;
}
