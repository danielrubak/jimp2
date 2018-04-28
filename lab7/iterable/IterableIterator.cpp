#include "IterableIterator.h"
#include <iostream>

using namespace utility;

ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left_begin,
                                        std::vector<std::string>::const_iterator right_begin,
                                        std::vector<int>::const_iterator left_end,
                                        std::vector<std::string>::const_iterator right_end) {
    left_vec_pos = left_begin;
    right_vec_pos = right_begin;
    left_vec_end = left_end;
    right_vec_end = right_end;
}

std::pair<int, std::string> ZipperIterator::Dereference() const {
    return std::make_pair(*left_vec_pos, *right_vec_pos);
}

IterableIterator &ZipperIterator::Next() {
    if ( left_vec_pos == (left_vec_end-1) && right_vec_pos == (right_vec_end-1) )
    {
        ++left_vec_pos;
        ++right_vec_pos;
    } else {
        if( left_vec_pos != (left_vec_end-1) )
            ++left_vec_pos;
        if( right_vec_pos != (right_vec_end-1))
            ++right_vec_pos;
    }
    return *this;
}

bool ZipperIterator::NotEquals(const std::unique_ptr<IterableIterator> &other) const {
    if ( right_vec_pos != other->right_vec_pos || left_vec_pos != other->left_vec_pos ) {
        return true;
    }
    return false;
}

EnumerateIterator::EnumerateIterator(std::vector<std::string>::const_iterator right_start,
                                              std::vector<std::string>::const_iterator right_end) {
    right_vec_pos = right_start;
    right_vec_end = right_end;
    number = 1;
}

std::pair<int, std::string> EnumerateIterator::Dereference() const {
    return std::make_pair(number, *right_vec_pos);
}

IterableIterator &EnumerateIterator::Next() {
    ++right_vec_pos;
    ++number;
    return *this;
}

bool EnumerateIterator::NotEquals(const std::unique_ptr<IterableIterator> &other) const {
    if ( right_vec_pos != other->right_vec_pos ) {
        return true;
    }
    return false;
}

ProductIterator::ProductIterator(std::vector<int>::const_iterator left_begin,
                                          std::vector<std::string>::const_iterator right_begin,
                                          std::vector<int>::const_iterator left_end,
                                          std::vector<std::string>::const_iterator right_end) {
    left_vec_pos = left_begin;
    right_vec_pos = right_begin;
    left_vec_end = left_end;
    right_vec_end = right_end;
    right_vec_first_elem = right_begin;
}

std::pair<int, std::string> ProductIterator::Dereference() const {
    return std::make_pair(*left_vec_pos, *right_vec_pos);
}

IterableIterator &ProductIterator::Next() {
    ++right_vec_pos;
    if ( right_vec_pos == right_vec_end ) {
        right_vec_pos = right_vec_first_elem;
        ++left_vec_pos;
    }
    if ( left_vec_pos == left_vec_end ) {
        right_vec_pos = right_vec_end;
    }
    return *this;
}

bool ProductIterator::NotEquals(const std::unique_ptr<IterableIterator> &other) const {
    if ( right_vec_pos != other->right_vec_pos || left_vec_pos != other->left_vec_pos ) {
        return true;
    }
    return false;
}