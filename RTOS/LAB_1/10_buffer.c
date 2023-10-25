#include <stdio.h>
#include <ctype.h>

int main() {
    char inputLine[1000]; // Assuming a maximum length of the input line is 1000 characters
    char buffer[1000]; // Buffer to store non-white space characters
    int bufferIndex = 0;

    printf("Enter a line of characters (including blanks and tabs):\n");
    fgets(inputLine, sizeof(inputLine), stdin);

    for (int i = 0; inputLine[i] != '\0'; ++i) {
        if (!isspace(inputLine[i])) {
            buffer[bufferIndex] = inputLine[i];
            bufferIndex++;
        }
    }

    buffer[bufferIndex] = '\0';

    printf("Characters without white spaces: %s\n", buffer);

    return 0;
}
