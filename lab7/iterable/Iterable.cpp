#include <iostream>
#include "Iterable.h"

using namespace utility;

IterableIteratorWrapper Iterable::cbegin() const {
    return IterableIteratorWrapper(ConstBegin());
}

IterableIteratorWrapper Iterable::cend() const {
    return IterableIteratorWrapper(ConstEnd());
}

IterableIteratorWrapper Iterable::begin() const {
    return cbegin();
}

IterableIteratorWrapper Iterable::end() const {
    return cend();
}

Zipper::Zipper(const std::vector<int> &vi, const std::vector<std::string> &vs) {
    vec_int = &vi;
    vec_str = &vs;
}

std::unique_ptr<IterableIterator> Zipper::ConstBegin() const {
    ZipperIterator it (vec_int->begin(), vec_str->begin(), vec_int->end(), vec_str->end());
    std::unique_ptr<IterableIterator> ptr = std::make_unique<ZipperIterator>(it);
    return ptr;
}

std::unique_ptr<IterableIterator> Zipper::ConstEnd() const {
    ZipperIterator it (vec_int->end(), vec_str->end(), vec_int->end(), vec_str->end());
    std::unique_ptr<IterableIterator> ptr = std::make_unique<ZipperIterator>(it);
    return ptr;
}

Enumerate::Enumerate(const std::vector<std::string> &vs) {
    vec_str = &vs;
}

std::unique_ptr<utility::IterableIterator> Enumerate::ConstBegin() const {
    EnumerateIterator it (vec_str->begin(), vec_str->end());
    std::unique_ptr<IterableIterator> ptr = std::make_unique<EnumerateIterator>(it);
    return ptr;
}

std::unique_ptr<IterableIterator> Enumerate::ConstEnd() const {
    EnumerateIterator it (vec_str->end(), vec_str->end());
    std::unique_ptr<IterableIterator> ptr = std::make_unique<EnumerateIterator>(it);
    return ptr;
}

Product::Product(const std::vector<int> &vi, const std::vector<std::string> &vs) {
    vec_int = &vi;
    vec_str = &vs;
}

std::unique_ptr<IterableIterator> Product::ConstBegin() const {
    ProductIterator it (vec_int->begin(), vec_str->begin(), vec_int->end(), vec_str->end());
    std::unique_ptr<IterableIterator> ptr = std::make_unique<ProductIterator>(it);
    return ptr;
}

std::unique_ptr<IterableIterator> Product::ConstEnd() const {
    ProductIterator it (vec_int->end(), vec_str->end(), vec_int->end(), vec_str->end());
    std::unique_ptr<IterableIterator> ptr = std::make_unique<ProductIterator>(it);
    return ptr;
}
