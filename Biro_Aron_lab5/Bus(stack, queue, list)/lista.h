//
// Created by Aaron on 2021. 01. 19..
//

#ifndef UNTITLED3_LISTA_H
#define UNTITLED3_LISTA_H
#include "verem.h"

using namespace std;

itemType *keres(itemType *h, custom d)
{
    while(!isEmpty(h))
    {
        if(h -> data == d)
            return h;
        h = h -> next;
    }
    return nullptr;
}

void del(itemType *&h, itemType *&e)
{
    if(e -> data == h -> data)
    {
        pop(h);
        return;
    }
    else
    {
        itemType *t = e;
        *e = *e -> next;
        delete t;
    }
}


void print(itemType *h)
{
    if(isEmpty(h))
    {
        cout<<"A lista amit ki szeretne iratni ures.\n";
        return;
    }
    while(!isEmpty(h))
    {
        if(h -> next == nullptr)
            cout<<h->data;
        else
            cout<<h->data<<", ";
        h = h -> next;
    }
    cout<<endl<<endl;
}

#endif //UNTITLED3_LISTA_H
