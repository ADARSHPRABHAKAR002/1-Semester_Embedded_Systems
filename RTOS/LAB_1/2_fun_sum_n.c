#include <stdio.h>

// Function to calculate the sum of first n numbers
int calculateSum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    return sum;
}

int main() {
    int n;

    // Ask the user to enter a positive integer
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Call the function to calculate the sum
    int sum = calculateSum(n);

    // Output the sum
    printf("Sum of first %d numbers is: %d\n", n, sum);

    return
