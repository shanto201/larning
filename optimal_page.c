#include <stdio.h>

int main() {
    int pages[50], frame[10];
    int n, frames;
    int i, j, k, pos, farthest;
    int pageFaults = 0, found, index;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for (i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\n");

    for (i = 0; i < n; i++) {
        found = 0;

        for (j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            for (j = 0; j < frames; j++) {
                if (frame[j] == -1) {
                    frame[j] = pages[i];
                    pageFaults++;
                    goto display;
                }
            }
            farthest = -1;
            pos = -1;

            for (j = 0; j < frames; j++) {
                for (k = i + 1; k < n; k++) {
                    if (frame[j] == pages[k])
                        break;
                }
                if (k == n) {
                    pos = j;
                    break;
                }

                if (k > farthest) {
                    farthest = k;
                    pos = j;
                }
            }
            frame[pos] = pages[i];
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
