#include <stdio.h>

int main() {
    int n, sum = 0;

    // Ask the user to enter a positive integer
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Calculate the sum of first n numbers
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }

    // Output the sum
    printf("Sum of first %d numbers is: %d\n", n, sum);

    return 0;
}
