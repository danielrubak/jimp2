#include "StudentRepository.h"

using namespace academia;

StudyYear& StudyYear::operator++() {
    (this->year_)++;
    return *this;
}

StudyYear& StudyYear::operator--() {
    (this->year_)--;
    return *this;
}

std::istream& operator>>(std::istream &is, StudyYear& y) {
    int year;
    is >> y.year_;
    return
}

std::ostream& operator<<(std::ostream& stream, const StudyYear& y) {
    stream << this->year_;
    return stream;
}

