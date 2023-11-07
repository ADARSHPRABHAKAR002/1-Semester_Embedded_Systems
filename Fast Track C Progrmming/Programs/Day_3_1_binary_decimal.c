#include <stdio.h>
#include <string.h>
#include <math.h>

int binaryToDecimal(char binary[]) {
    int decimal = 0;
    int length = strlen(binary);

    // Iterate through the binary number in reverse order
    for (int i = length - 1; i >= 0; --i) {
        // Convert character '0' or '1' to integer 0 or 1
        int digit = binary[i] - '0';

        // Add the decimal equivalent of the binary digit to the result
        decimal += digit * pow(2, length - 1 - i);
    }

    return decimal;
}

int main() {
    char binary[32]; // Assuming a maximum length of 32 bits for the binary number

    // Read the binary number as a string
    printf("Enter a binary number: ");
    scanf("%s", binary);

    // Convert binary to decimal
    int decimal = binaryToDecimal(binary);

    // Output the decimal number
    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}
