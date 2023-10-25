#include <stdio.h>
#include <ctype.h>

int main() {
    char inputLine[100]; 
    int alphabetsCount = 0;
    int spacesCount = 0;

    printf("Enter a line of input: ");
    fgets(inputLine, sizeof(inputLine), stdin);

    for (int i = 0; inputLine[i] != '\0'; ++i) {
        if (isalpha(inputLine[i])) {
            alphabetsCount++;
        } else if (inputLine[i] == ' ' || inputLine[i] == '\t') {
            spacesCount++;
        }
    }

    printf("Number of alphabets: %d\n", alphabetsCount);
    printf("Number of white spaces: %d\n", spacesCount);

    return 0;
}
