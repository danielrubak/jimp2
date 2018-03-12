#include "SimpleForwardList.h"

int main() {
    ForwardList *iter;
    std::cout << "First element of list: " << std::endl;
    ForwardList *newForwardList = CreateNode(7);
    std::cout << newForwardList->value << ", " << newForwardList->next << std::endl;

    std::cout << "\nList after PushFront(): " << std::endl;
    newForwardList = PushFront(newForwardList, 12);
    iter = newForwardList;
    while ( iter != nullptr ) {
        std::cout << "Address of the next node:" << iter->next << ", Value: " << iter->value << std::endl;
        iter = iter->next;
    }

    std::cout << "\nList after Append(): " << std::endl;
    ForwardList *newTail = CreateNode(2);
    Append(newForwardList, newTail);
    iter = newForwardList;
    while ( iter != nullptr ) {
        std::cout << "Address of the next node:" << iter->next << ", Value: " << iter->value << std::endl;
        iter = iter->next;
    }

    DestroyList(newForwardList);
    return 0;
}