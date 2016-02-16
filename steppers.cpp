// Define a list of functions that we can use to get to the target

#include <math.h>

int add(int first, int second) {
    return first + second;
}

int subtract(int first, int second) {
    return first - second;
}

int multiply(int first, int second) {
    return first * second;
}

int divide(int numerator, int denominator) {
    if (denominator <= 0) {
        return 0;
    }

    float result = (float) numerator / (float) denominator;

    if (ceil(result) != result) {
        return 0;
    }

    return (int) result;
}

