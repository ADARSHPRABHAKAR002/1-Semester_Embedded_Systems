#include <stdio.h>

int findSmallest(int array[], int length) {

    for (int i = 1; i < length; ++i) {
        if (array[i] < smallest) {
            smallest = array[i];
        }
    }

    return smallest;
}

int main() {
    int length;

    printf("Enter the length of the array: ");
    scanf("%d", &length);

    int array[length];

    printf("Enter %d integers:\n", length);
    for (int i = 0; i < length; ++i) {
        scanf("%d", &array[i]);
    }

    int smallest = findSmallest(array, length);

    printf("The smallest number in the array is: %d\n", smallest);

    return 0;
}
