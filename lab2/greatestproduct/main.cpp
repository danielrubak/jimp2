#include "GreatestProduct.h"

int main() {
    std::vector<int> intNumbersVector = {-11, -90, -4, -5, -9, -1, -3, -1};
    int k = 3;
    int functionResult = GreatestProduct(intNumbersVector, k);
    std::cout << "Call function: " << functionResult << std::endl;

    return 0;
}