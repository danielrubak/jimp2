#include <FactoryMethod.h>
#include <complex>
#include <memory>

int main() {
    std::cout << factoryMethod::Add(2,3) << std::endl;
    std::cout << factoryMethod::Add(2.0,3.0) << std::endl;
    std::complex<double> z1 = 1i * 1i;
    std::complex<double> z2 = 1i * 1i;
    std::cout << factoryMethod::Add(z1, z2) << std::endl;
    std::unique_ptr<int> ptr = std::make_unique<int>();
    *ptr = 15;
    std::cout << factoryMethod::Value(ptr) << std::endl;
    int *p1 = new int (33);
    std::cout << factoryMethod::Value(p1) << std::endl;
    return 0;
}