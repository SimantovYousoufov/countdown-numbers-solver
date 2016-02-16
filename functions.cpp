#include <stdlib.h>
#include <time.h>

// Divides size of whole array with that of an individual element
// @todo this is bad
#define arraySize(array) (sizeof(array) / sizeof(array[0]))

int maxInt(int *numbers) {
    int max = numbers[0];
    int length = arraySize(numbers);

    for (int i = 0; i < length; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }

    return max;
}

int minInt(int *numbers) {
    int min = numbers[0];
    int length = arraySize(numbers);

    for (int i = 0; i < length; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }

    return min;
}

int randomInt(int min, int max) {
    return rand() % max + min;
}