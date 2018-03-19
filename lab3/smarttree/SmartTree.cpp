#include "SmartTree.h"

std::unique_ptr<datastructures::SmartTree> datastructures::CreateLeaf(int value) {
    std::unique_ptr<SmartTree> smart_tree = std::make_unique<SmartTree>();
    smart_tree->value = value;
    return smart_tree;
}

std::unique_ptr<datastructures::SmartTree>
datastructures::InsertLeftChild(std::unique_ptr<datastructures::SmartTree> tree,
                                std::unique_ptr<datastructures::SmartTree> left_subtree) {
    tree->left = std::move(left_subtree);
    return tree;
}

std::unique_ptr<datastructures::SmartTree>
datastructures::InsertRightChild(std::unique_ptr<datastructures::SmartTree> tree,
                                 std::unique_ptr<datastructures::SmartTree> right_subtree) {
    tree->right = std::move(right_subtree);
    return tree;
}

void datastructures::PrintTreeInOrder(const std::unique_ptr<datastructures::SmartTree> &unique_ptr, std::ostream *out) {
    if (unique_ptr->left) {
        PrintTreeInOrder((unique_ptr->left), out);
    }
    *out << (unique_ptr->value) << ", ";
    if (unique_ptr->right) {
        PrintTreeInOrder((unique_ptr->right), out);
    }
}

std::string datastructures::PrintLeaf(const std::unique_ptr<datastructures::SmartTree> &tree) {
    std::string str = " [";
    if ( !tree ) {
        str += "none";
    } else {
        str += std::to_string(tree->value);
        str += PrintLeaf(tree->left);
        str += PrintLeaf(tree->right);
    }
    return (str += "]");
}

std::string datastructures::DumpTree(const std::unique_ptr<datastructures::SmartTree> &tree) {
    if( !tree )
        // just in case
        return "";
    std::string dump_tree_string;
    dump_tree_string = PrintLeaf(tree);
    dump_tree_string.erase(0, 1);
    return dump_tree_string;
}

std::unique_ptr<datastructures::SmartTree> datastructures::RestoreTree(const std::string &tree) {
    std::string string_to_erase = tree;
    string_to_erase.erase(std::remove(string_to_erase.begin(), string_to_erase.end(), '['), string_to_erase.end());
    string_to_erase.erase(std::remove(string_to_erase.begin(), string_to_erase.end(), ']'), string_to_erase.end());
    std::cout << string_to_erase << std::endl;
    std::istringstream iss(string_to_erase);
    std::vector<std::string> tree_values_vector {std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{}};
    std::unique_ptr<datastructures::SmartTree> root;
    if ( tree_values_vector.size() == 0 ) {
        return nullptr;
    } else if ( tree_values_vector.size() == 3 ) {
        int value;
        std::istringstream(tree_values_vector[0]) >> value;
        root = CreateLeaf(value);
    }
    return root;
}