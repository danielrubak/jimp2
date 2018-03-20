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
    std::string values;
    std::queue <char> bracketsQueue;
    std::queue <std::string> valuesQueue;

    for ( auto it = tree.begin(); it!= tree.end(); it++ ) { ;
        if ( isdigit(*it) || *it == '-' ) {
            values += *it;
        } else if (isspace(*it)) {
            values += " ";
        } else if ( isalpha(*it) ) {
            values += *it;
        } else {
            bracketsQueue.push(*it);
        }
    }
    std::cout << "Restore tree: " << tree << std::endl;

    std::istringstream buffer(values);
    std::vector<std::string> leafs_values_vector ((std::istream_iterator<std::string>(buffer)), std::istream_iterator<std::string>());
    for ( auto it = leafs_values_vector.begin(); it!= leafs_values_vector.end(); it++ ) {
        valuesQueue.push(*it);
    }

    std::cout << "Brackets number: " << bracketsQueue.size() << std::endl;
    std::cout << "Values number: " << valuesQueue.size() << std::endl;
    std::unique_ptr<SmartTree> root;
    auto tree_root = CreateLeafOnPosition(root, bracketsQueue, valuesQueue);
    return tree_root;
}

std::unique_ptr <datastructures::SmartTree> datastructures::CreateLeafOnPosition (std::unique_ptr <datastructures::SmartTree> &tree, std::queue<char > &brackets, std::queue<std::string> &values) {
    if ( !tree ) {
        if ( brackets.front() == '[' && values.front() == "none" )
            return nullptr;
        else {
            int value = 0;
            std::istringstream ( values.front() ) >> value;
            tree = CreateLeaf(value);
            brackets.pop();
            values.pop();
        }
        return CreateLeafOnPosition(tree, brackets, values);
    } else {
        // left side of tree
        if ( brackets.front() == '[' && values.front() != "none" ) {
            int value = 0;
            std::istringstream ( values.front() ) >> value;
            tree = InsertLeftChild(std::move(tree), CreateLeaf(value));
            brackets.pop();
            values.pop();
            tree->left = CreateLeafOnPosition(tree->left, brackets, values);
            brackets.pop();
        } else {
            brackets.pop();
            brackets.pop();
            values.pop();
        }

        //right side of tree
        if ( brackets.front() == '[' && values.front() != "none" ) {
            int value = 0;
            std::istringstream ( values.front() ) >> value;
            tree = InsertRightChild(std::move(tree), CreateLeaf(value));
            brackets.pop();
            values.pop();
            tree->right = CreateLeafOnPosition(tree->right, brackets, values);
            brackets.pop();
        } else {
            brackets.pop();
            brackets.pop();
            values.pop();
        }
    }
    return std::move(tree);
}