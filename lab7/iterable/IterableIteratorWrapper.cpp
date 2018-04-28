#include "IterableIteratorWrapper.h"

using namespace utility;

IterableIteratorWrapper::IterableIteratorWrapper(std::unique_ptr<IterableIterator> iterator) {
    it = move(iterator);
}

bool IterableIteratorWrapper::operator!=(const IterableIteratorWrapper &other) const {
    return it->NotEquals(other.it);
}

std::pair<int, std::string> IterableIteratorWrapper::operator*() const {
    return it->Dereference();
}

IterableIteratorWrapper &IterableIteratorWrapper::operator++() {
    it->Next();
    return *this;
}