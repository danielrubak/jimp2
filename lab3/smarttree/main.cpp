#include "SmartTree.h"

int main() {
    std::unique_ptr<datastructures::SmartTree> root;
    root = datastructures::CreateLeaf(99);
    root = datastructures::InsertLeftChild(move(root), datastructures::CreateLeaf(100));
    root = datastructures::InsertRightChild(move(root), datastructures::CreateLeaf(88));
    root->left = datastructures::InsertLeftChild(move(root->left), datastructures::CreateLeaf(1234));
    root->left = datastructures::InsertRightChild(move(root->left), datastructures::CreateLeaf(4321));
    root->right = datastructures::InsertLeftChild(move(root->right), datastructures::CreateLeaf(897));
    root->right = datastructures::InsertRightChild(move(root->right), datastructures::CreateLeaf(761));
    auto tree = DumpTree(root);
    std::cout << tree << std::endl;

    std::string str = "[99 [100 [1234 [none] [none]] [4321 [none] [none]]] [88 [897 [none] [none]] [761 [none] [none]]]]";
    auto tree_2 = datastructures::RestoreTree(str);

    return 0;
}