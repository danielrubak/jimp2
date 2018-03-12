//
// Created by daniel on 12.03.18.
//

#include "SimpleForwardList.h"

ForwardList *CreateNode(int value) {
    ForwardList *node = new ForwardList;
    node->next = nullptr;
    node->value = value;
    return node;
}

void DestroyList(ForwardList *list) {
    ForwardList *next = nullptr;
    while ( list != nullptr ) {
        next = list->next;
        delete list;
        list = next;
    }
}

ForwardList *PushFront(ForwardList *list, int value) {
    if ( list == nullptr ) {
        return nullptr;
    }
    ForwardList *oldHead = list;
    ForwardList *newHead = new ForwardList;
    newHead->next = oldHead;
    newHead->value = value;
    oldHead->next = nullptr;
    return newHead;
}

void Append(ForwardList *list, ForwardList *tail) {
    if ( list == nullptr ) {
        list = tail;
        list->next = nullptr;
        list->value = tail->value;
    } else {
        while (list->next != nullptr) {
            list = list->next;
        }
        list->next = tail;
    }
}
