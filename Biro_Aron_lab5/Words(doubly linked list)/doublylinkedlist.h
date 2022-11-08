//
// Created by Aaron on 2021. 01. 18..
//

#ifndef UNTITLED1_DOUBLYLINKEDLIST_H
#define UNTITLED1_DOUBLYLINKEDLIST_H

typedef std::string custom;

struct itemType{
    custom data;
    itemType *prev, *next;
};

struct dlList{
    itemType *head, *tail;
};

void init(dlList &h)
{
    h.head = new itemType;
    h.tail = new itemType;
    h.head -> next = h.tail;
    h.head -> prev = nullptr;
    h.tail -> prev = h.head;
    h.tail -> next = nullptr;
}

/*itemType *firstOccurence(dlList h, custom d)
{
    while(h.head != h.tail)
    {
        if(h.head -> data == d)
            return h.head;
        h.head = h.head -> next;
    }
    return nullptr;
}

/*void insertBefore(dlList &h, custom d, custom b)
{
    itemType *s = firstOccurence(h, d);
    if(s == nullptr)
    {
        std::cout<<"A beszurasi hely nem leteik.\n";
        return;
    }
    else
    {
        itemType *t = new itemType;
        t -> data = b;
        t -> next = s;
        s -> prev -> next = t;
        t -> prev = s -> prev;
        s -> prev = t;
    }
}

void insertAfter(dlList &h, custom d, custom b)
{
    itemType *s = firstOccurence(h, d);
    if(s == nullptr)
    {
        std::cout<<"A beszurasi hely nem leteik.\n";
        return;
    }
    else
    {
        itemType *t = new itemType;
        t -> data = b;
        t -> next = s -> next;
        s -> next = t;
        t -> prev = s;
        s -> prev -> next = t;
    }
}

void del(dlList &h, custom d)
{
    itemType *t = firstOccurence(h, d);
    if(t == nullptr)
    {
        std::cout<<"Nincs ilyen elem a listaban.\n";
        return;
    }
    t -> prev -> next = t -> next;
    t -> next -> prev = t -> prev;
    delete t;
}*/

void add(dlList &h, custom d)
{
    itemType *t = new itemType;
    t -> data = d;
    h.tail -> prev -> next = t;
    t -> next = h.tail;
    t -> prev = h.tail -> prev;
    h.tail -> prev = t;
}

void print(dlList h)
{
    h.head = h.head -> next;
    while(h.head != h.tail)
    {
        if(h.head == h.tail -> prev)
            std::cout<<h.head->data;
        else
            std::cout<<h.head->data<<", ";
        h.head = h.head -> next;
    }
    std::cout<<std::endl;
}

void printReverse(dlList h)
{
    h.tail = h.tail -> prev;
    while(h.tail != h.head )
    {
        if(h.tail == h.head -> next)
            std::cout<<h.tail->data;
        else
            std::cout<<h.tail->data<<", ";
        h.tail = h.tail -> prev;
    }
    std::cout<<std::endl;
}


#endif //UNTITLED1_DOUBLYLINKEDLIST_H
