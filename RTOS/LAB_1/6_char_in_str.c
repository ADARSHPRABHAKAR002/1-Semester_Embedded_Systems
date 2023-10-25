    #include <stdio.h>

int main() {
    char inputString[100]; // Assuming a maximum length of the input string is 100 characters
    int count = 0;

    // Ask the user to enter a string
    printf("Enter a string: ");
    scanf("%[^\n]s", inputString); // Read the whole line, including spaces, until a newline is encountered

    // Count the number of characters in the string without using strlen
    for (int i = 0; inputString[i] != '\0'; ++i) {
        count++;
    }

    // Output the total number of characters in the string
    printf("Total number of characters in the string: %d\n", count);

    return 0;
}
