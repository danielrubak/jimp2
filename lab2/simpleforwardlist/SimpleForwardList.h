#ifndef JIMP_EXERCISES_SIMPLEFORWARDLIST_H
#define JIMP_EXERCISES_SIMPLEFORWARDLIST_H

#include <iostream>

struct ForwardList {
    int value;
    ForwardList *next;
};

ForwardList *CreateNode(int value);
void DestroyList(ForwardList *list);
ForwardList *PushFront(ForwardList *list, int value);
void Append(ForwardList *list, ForwardList *tail);

#endif //JIMP_EXERCISES_SIMPLEFORWARDLIST_H
