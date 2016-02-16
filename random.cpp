#include <iostream>
#include <vector>
#include <map>
#include <array>
#include "files.h"

// Function pointer is of type int
typedef int (*FnPtr)(int, int);

/*
 * Solve Countdown with a random approach
 */
std::vector<std::string> random(const int target, const std::vector<int> numbers) {
    unsigned int cycles = 0;

    // Keep a history of completed steps
    std::vector<std::string> completedSteps;

    // Map the available step functions
    std::map<std::string, FnPtr> stepMap;
    stepMap["add"] = add;
    stepMap["subtract"] = subtract;
    stepMap["divide"] = divide;
    stepMap["multiply"] = multiply;

    // A vector of available map keys
    std::vector<std::string> stepKeys = { "add", "subtract", "divide", "multiply" };

    int currentPosition = 0;

    // ignore steps that don't include the current position after the first loop through
    while (currentPosition != target) {
        std::vector<int> workingNumbers = numbers;
        completedSteps.clear(); // Reset step counter
        currentPosition = 0; // Reset current position
        workingNumbers.push_back(currentPosition);

        while ((currentPosition != target) && (workingNumbers.size() > 1)) {
            int randKeyIndex = rand() % stepKeys.size();
            std::string key = stepKeys[randKeyIndex];
            FnPtr step = stepMap[key];

            unsigned int firstIndex;
            unsigned int secondIndex;

            if (currentPosition > 0) {
                firstIndex = workingNumbers.size() - 1; // always last (current position)
            } else {
                firstIndex = rand() % (workingNumbers.size());
            }

            unsigned int firstNumber = workingNumbers[firstIndex];

            do {
                secondIndex = rand() % (workingNumbers.size());
            } while(firstIndex == secondIndex);

            unsigned int secondNumber = workingNumbers[secondIndex];
            workingNumbers.erase(workingNumbers.begin() + firstIndex);

            if (firstIndex > secondIndex) {
                workingNumbers.erase(workingNumbers.begin() + secondIndex);
            } else {
                workingNumbers.erase(workingNumbers.begin() + secondIndex - 1);
            }

            if (currentPosition == 0) {
                // Remove old current position if this is the first inner iteration
                workingNumbers.pop_back();
            }

            currentPosition = step(firstNumber, secondNumber);
            workingNumbers.push_back(currentPosition); // update with the new current position

            if (currentPosition == 0) {
                break; // made no progress or encountered an error
            }

            completedSteps.push_back("" + std::to_string(firstNumber) + ' ' + key + ' ' + std::to_string(secondNumber));

            cycles++;

            if (target == currentPosition) {
                // found it
                std::cout << "Solved in " << cycles << " cycles" << std::endl;
                return completedSteps;
            } else if ((currentPosition > target) || (currentPosition < 0) || (workingNumbers.size() == 0)) {
                // Didn't find it, start over
                break;
            }
        }
    }

    return completedSteps;
}
