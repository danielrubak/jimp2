#ifndef JIMP2_FACTORYMETHOD_H
#define JIMP2_FACTORYMETHOD_H

#include <iostream>

namespace factoryMethod {
    template<class T>
    T Create() {
        return T();
    }

    template<class T>
    T Add (const T el1, const T el2) {
        return el1 + el2;
    }

    template <typename T>
    auto Value (const T &t) {
        return *t;
    }

    class MyType {
    public:
        MyType() : message("hello") {};
        std::string SayHello() { return message; }
    private:
        std::string message;
    };
}

#endif //JIMP2_FACTORYMETHOD_H
