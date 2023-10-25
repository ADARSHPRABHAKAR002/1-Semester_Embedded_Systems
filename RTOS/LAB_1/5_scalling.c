#include <stdio.h>

void scaleArray(int array[], int length, int k) {
    for (int i = 0; i < length; ++i) {
        array[i] *= k;
    }
}

int main() {
    int length, k;

    printf("Enter the length of the array: ");
    scanf("%d", &length);

    int array[length];

    printf("Enter %d integers:\n", length);
    for (int i = 0; i < length; ++i) {
        scanf("%d", &array[i]);
    }

    printf("Enter the scale factor 'k': ");
    scanf("%d", &k);

    printf("Original array: ");
    for (int i = 0; i < length; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    scaleArray(array, length, k);

    printf("Scaled array (scaled by %d): ", k);
    for (int i = 0; i < length; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
