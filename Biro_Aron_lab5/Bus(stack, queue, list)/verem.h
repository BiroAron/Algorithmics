//
// Created by Aaron on 2021. 01. 19..
//

#ifndef UNTITLED3_VEREM_H
#define UNTITLED3_VEREM_H

using namespace std;

typedef string custom;

struct itemType{
    custom data;
    itemType *next;
};

void init(itemType *&h)
{
    *&h = nullptr;
}

bool isEmpty(itemType *h)
{
    return h == nullptr;
}

void push(itemType *&h, custom d)
{
    itemType *t = new itemType;
    t -> data = d;
    t -> next = h;
    h = t;
}

void pop(itemType *&h)
{
    if(isEmpty(h))
    {
        cout<<"A verem amibol torolni szeretne ures.\n";
        return;
    }
    if(!isEmpty(h))
    {
        itemType *t = h;
        h = h -> next;
        delete t;
    }
}

#endif //UNTITLED3_VEREM_H
