#include <stdio.h>

// Function to calculate the sum of digits of a number
int calculateDigitSum(int number) {
    int sum = 0;
    
    // Take the absolute value of the number to handle negative inputs
    number = abs(number);
    
    while (number != 0) {
        sum += number % 10; // Add the last digit to the sum
        number /= 10; // Remove the last digit from the number
    }
    
    return sum;
}

int main() {
    int num;

    // Ask the user to enter a number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Call the function to calculate digit sum and output the result
    int digitSum = calculateDigitSum(num);
    printf("Sum of digits: %d\n", digitSum);

    return 0;
}
``
