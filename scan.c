#include <stdio.h>
int main() {
    int n, head, diskSize, i, j;
    int req[50], temp;
    int totalSeek = 0, cur;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }
    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &diskSize);
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (req[i] > req[j]) {
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    cur = head;
    printf("\nSeek Sequence: %d", cur);


    for (i = 0; i < n; i++) {
        if (req[i] >= head) {
            totalSeek += abs(cur - req[i]);
            cur = req[i];
            printf(" -> %d", cur);
        }
    }


    totalSeek += abs(cur - (diskSize - 1));
    cur = diskSize - 1;
    printf(" -> %d", cur);


    for (i = n - 1; i >= 0; i--) {
        if (req[i] < head) {
            totalSeek += abs(cur - req[i]);
            cur = req[i];
            printf(" -> %d", cur);
        }
    }

    printf("\nTotal Seek Time = %d\n", totalSeek);
    return 0;
}
