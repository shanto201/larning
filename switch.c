#include <stdio.h>

// Function declaration
int square(int n);

int main() {
    int number, result;

    // Ask the user for a number
    printf("Enter a number: ");
    scanf("%d", &number);

    // Call the function to calculate the square
    result = square(number);

    // Print the result
    printf("The square of %d is %d\n", number, result);

    return 0;
}

// Function definition
int square(int n) {
    return n * n;
}

