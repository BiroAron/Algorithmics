//
// Created by Aaron on 2021. 02. 03..
//

#ifndef MAIN_CPP_FELADAT1_HEADER1_H
#define MAIN_CPP_FELADAT1_HEADER1_H

#include <string>

using namespace std;

typedef string CUSTOM;

struct list{
    CUSTOM data;
    list *next;
};

void init(list *&h)
{
    h = nullptr;
}

void push(list *&h, CUSTOM d)
{
    list *t = new list;
    t->next = h;
    t->data = d;
    h = t;
}

void del(list *h, CUSTOM d)
{
    while (h->next != nullptr)
    {
        if (h-> next -> data == d)
        {
            list *t = h -> next;
            h -> next = h->next->next;
            delete t;
            return;
        }
        h = h->next;
    }
}

void pop(list *&h)
{
    list *t = h;
    h = h->next;
    delete t;
}

list *WhereIsIt(list *h, CUSTOM d)
{
    while(h != nullptr)
    {
        if(h  -> data == d)
            return h;
        h = h -> next;
    }
    return nullptr;
}

void print(list *h)
{
    while(h != nullptr)
    {
        if(h->next != nullptr)
            cout << h -> data << " -> ";
        else
            cout << h -> data;
        h = h -> next;
    }
    cout<<endl;
}

#endif //MAIN_CPP_FELADAT1_HEADER1_H
