//
// Created by Aaron on 2021. 01. 16..
//

#ifndef UNTITLED_STACK_H
#define UNTITLED_STACK_H

typedef char CUSTOM;

struct itemType{
    CUSTOM data;
    itemType *next;
};

void init(itemType *&h)
{
    h = nullptr;
}

void push(itemType *&h, CUSTOM d)
{
    itemType *t = new itemType;
    t->next = h;
    t->data = d;
    h=t;
}

void pop(itemType *&h)
{
    if(h==nullptr)
    {
        std::cout<<"a lita ures";
        return;
    }
    else
    {
        itemType *t = h;
        h=h->next;
        delete t;
    }
}
#endif //UNTITLED_STACK_H
