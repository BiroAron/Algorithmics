//
// Created by Aaron on 2021. 01. 19..
//

#ifndef UNTITLED3_VARAKOZASISOR_H
#define UNTITLED3_VARAKOZASISOR_H
#include "verem.h"

using namespace std;

struct queue{
    itemType *head;
    itemType *tail;
};

void initQ(queue &h)
{
    h.head = nullptr;
    h.tail = nullptr;
}

void enqueue(queue &h, custom d)
{
    itemType *t = new itemType;
    t -> data = d;
    t -> next = nullptr;
    if(isEmpty(h.head))
        h.head = t;
    else
        h.tail -> next = t;
    h.tail = t;
}

void dequeue(queue &h)
{
    if(isEmpty(h.head))
    {
        cout<<"A varakozasi sor ures, nem lehet torolni tobb elemet.\n";
        return;
    }
    if(!isEmpty(h.head))
    {
        itemType *t = h.head;
        h.head = h.head -> next;
        delete t;
    }
}

#endif //UNTITLED3_VARAKOZASISOR_H
