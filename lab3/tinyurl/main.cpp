#include "TinyUrl.h"

int main() {
    std::array<char, 6> *ptr = new std::array<char, 6> ({'0','9','9','9','9','9'});
    tinyurl::NextHash(ptr);
    for ( int j = 0; j < (*ptr).size(); j++ ) {
        std::cout << (*ptr)[j] << std::endl;
    }
    return 0;
}
