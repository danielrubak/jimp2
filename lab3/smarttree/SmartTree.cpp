#include "SmartTree.h"

std::unique_ptr <datastructures::SmartTree> datastructures::CreateLeaf(int value) {
    std::unique_ptr<SmartTree> smart_tree = std::make_unique<SmartTree>();
    smart_tree->value = value;
    return smart_tree;
}

std::unique_ptr <datastructures::SmartTree> datastructures::InsertLeftChild(std::unique_ptr<datastructures::SmartTree> tree, std::unique_ptr<datastructures::SmartTree> left_subtree) {
    tree->left = std::move(left_subtree);
    return tree;
}

std::unique_ptr <datastructures::SmartTree> datastructures::InsertRightChild(std::unique_ptr<datastructures::SmartTree> tree, std::unique_ptr<datastructures::SmartTree> right_subtree) {
    tree->right = std::move(right_subtree);
    return tree;
}

void datastructures::PrintTreeInOrder(const std::unique_ptr<datastructures::SmartTree> &unique_ptr, std::ostream *out) {
    if( unique_ptr->left ) {
        PrintTreeInOrder( (unique_ptr->left), out );
    }
    *out << (unique_ptr->value) << ", ";
    if( unique_ptr->right ) {
        PrintTreeInOrder( (unique_ptr->right), out );
    }
}

std::string datastructures::DumpTree(const std::unique_ptr<datastructures::SmartTree> &tree) {

}

std::unique_ptr <datastructures::SmartTree> datastructures::RestoreTree(const std::string &tree) {

}