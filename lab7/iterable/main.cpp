#include <iostream>
#include "Iterable.h"

int main() {
    const std::vector<int> vi {4, 77, -91};
    const std::vector<std::string> vs {"4", "9991", "adfskld"};
    for (const auto &p : utility::Zipper(vi, vs)) {
        std::cout << "(" << p.first << ", \"" << p.second << "\") ";
    }
    std::cout << std::endl;
    //Expected result: (4, "4") (77, "9991") (-91,"adfskld")

    for (const auto &p : utility::Enumerate(vs)) {
        std::cout << "(" << p.first << ", \"" << p.second << "\") ";
    }
    std::cout << std::endl;
    //Expected result: (1, "4") (2, "9991") (3,"adfskld")

    for (const auto &p : utility::Product(vi,vs)) {
        std::cout << "(" << p.first << ", \"" << p.second << "\") ";
    }
    std::cout << std::endl;
    //Expected result: (4, "4") (4,"9991") (4, "adfskld") (77, "4") (77,"9991") (77, "adfskld") (-91,"4") (-91,"9991") (-91, "adfskld")
    return 0;
}

