#include <iostream>
#include <vector>
#include <map>
#include <array>
#include "files.h"

#define US_TO_S 0.000001

typedef std::chrono::high_resolution_clock::time_point HRTimeVar;
typedef std::chrono::microseconds microseconds;

int main() {
    srand(time(0));
    std::vector<int> numbers = {100, 75, 50, 8, 6, 3};

    HRTimeVar start = std::chrono::high_resolution_clock::now();
    std::vector<std::string> result = random(767, numbers);
    HRTimeVar end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<microseconds>(end - start).count();

    for (std::vector<std::string>::const_iterator i = result.begin(); i != result.end(); ++i) {
        std::cout << *i;

        if (i != (result.end() - 1)) {
            std::cout << " => ";
        }
    }
    std::cout << std::endl;

    std::cout << "Total duration: " << duration * US_TO_S << " seconds" << std::endl;

    return 0;
}
