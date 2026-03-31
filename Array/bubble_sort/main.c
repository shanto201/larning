#include <stdio.h>

// Function for Binary Search
int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;  // Element found at index mid

        if (arr[mid] < key)
            low = mid + 1; // Search right half
        else
            high = mid - 1; // Search left half
    }
    return -1; // Element not found
}

// Main function
int main() {
    int arr[] = {2, 4, 7, 10, 15, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, n, key);

    if (result == -1)
        printf("Element %d not found in the array.\n", key);
    else
        printf("Element %d found at index %d.\n", key, result);

    return 0;
}
