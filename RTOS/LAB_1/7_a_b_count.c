#include <stdio.h>

void countCharacters(char *str, int *countA, int *countB) {
    *countA = 0;
    *countB = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == 'a') {
            (*countA)++;
        } else if (str[i] == 'b') {
            (*countB)++;
        }
    }
}

int main() {
    char inputString[100]; // Assuming a maximum length of the input string is 100 characters
    int countA, countB;

    printf("Enter a string: ");
    scanf("%[^\n]s", inputString); // Read the whole line, including spaces, until a newline is encountered

    countCharacters(inputString, &countA, &countB);

    printf("Number of 'a' characters: %d\n", countA);
    printf("Number of 'b' characters: %d\n", countB);

    return 0;
}
