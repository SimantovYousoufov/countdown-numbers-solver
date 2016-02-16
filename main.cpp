#include <iostream>
#include <vector>
#include <map>
#include <array>
#include "files.h"

int main() {
    srand(time(0));
    std::vector<int> numbers = {100, 75, 50, 8, 6, 3};
    std::vector<std::string> result = random(767, numbers, 0);

    for (std::vector<std::string>::const_iterator i = result.begin(); i != result.end(); ++i) {
        std::cout << *i;

        if (i != (result.end() - 1)) {
            std::cout << " => ";
        }
    }

    return 0;
}
