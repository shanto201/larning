#include <stdio.h>

void indexedAllocation() {
    int files, i, j;
    int indexBlock[20];
    int dataBlocks;

    printf("Enter number of files: ");
    scanf("%d", &files);

    for (i = 1; i <= files; i++) {
        printf("\nFile %d\n", i);

        printf("Enter index block: ");
        scanf("%d", &indexBlock[i]);

        printf("Enter number of data blocks: ");
        scanf("%d", &dataBlocks);

        int blocks[dataBlocks];

        printf("Enter data blocks:\n");
        for (j = 0; j < dataBlocks; j++) {
            scanf("%d", &blocks[j]);
        }

        printf("\nFile %d allocated as:\n", i);
        printf("Index Block %d -> ", indexBlock[i]);

        for (j = 0; j < dataBlocks; j++) {
            printf("%d ", blocks[j]);
        }
        printf("\n");
    }
}
int main() {
    printf("Indexed File Allocation Method\n");
    indexedAllocation();
    return 0;
}
