#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, j;
    int req[50], visited[50] = {0};
    int totalSeek = 0, cur, min, index;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    cur = head;

    printf("\nSeek Sequence: %d", cur);

    for (i = 0; i < n; i++) {
        min = 9999;
        for (j = 0; j < n; j++) {
            if (!visited[j] && abs(cur - req[j]) < min) {
                min = abs(cur - req[j]);
                index = j;
            }
        }

        visited[index] = 1;
        totalSeek += abs(cur - req[index]);
        cur = req[index];

        printf(" -> %d", cur);
    }

    printf("\nTotal Seek Time = %d\n", totalSeek);
    return 0;
}
