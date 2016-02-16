#ifndef FILES_H
#define FILES_H

#include <vector>

int maxInt(int *numbers);

int minInt(int *numbers);

int randomInt(int min, int max);

int add(int first, int second);

int subtract(int first, int second);

int multiply(int first, int second);

int divide(int numerator, int denominator);

std::vector<std::string> random(const int target, const std::vector<int> numbers);

#endif
