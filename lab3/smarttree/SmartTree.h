#ifndef JIMP2_SMARTTREE_H
#define JIMP2_SMARTTREE_H

#include <iostream>
#include <memory>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <iterator>
#include <cmath>

namespace datastructures {
    struct SmartTree {
        int value;
        std::unique_ptr<SmartTree> left;
        std::unique_ptr<SmartTree> right;
    };

    std::unique_ptr <SmartTree> CreateLeaf(int value);
    std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree);
    std::unique_ptr <SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree);
    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out);
    std::string DumpTree(const std::unique_ptr<SmartTree> &tree);
    std::string PrintLeaf(const std::unique_ptr<SmartTree> &tree);
    std::unique_ptr <SmartTree> RestoreTree(const std::string &tree);
}
#endif //JIMP2_SMARTTREE_H
