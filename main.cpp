#include <iostream>
#include <vector>
#include <map>
#include <array>
#include "files.h"

int main() {
    srand(time(0));
    std::vector<int> numbers = {100, 75, 50, 8, 6, 3};
    std::vector<std::string> result = simple(767, numbers, 0);
    std::cout << "Found ";

    for (std::vector<std::string>::const_iterator i = result.begin(); i != result.end(); ++i) {
        std::cout << *i << ' ';
    }
    return 0;
}
