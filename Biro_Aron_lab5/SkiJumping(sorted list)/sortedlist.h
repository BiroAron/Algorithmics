//
// Created by Aaron on 2021. 01. 18..
//

#ifndef UNTITLED2_SORTEDLIST_H
#define UNTITLED2_SORTEDLIST_H

struct itemType{
    int points;
    std::string name;
    itemType *next;
};

struct linkedList{
    itemType *head;
    itemType *tail;
};

void init(linkedList &h)
{
    h.head = nullptr;
    h.tail = nullptr;
}

bool isEmpty(linkedList h)
{
    return h.head == nullptr;
}

itemType *find(linkedList h, int pont)
{
    if(h.head -> points <= pont)
        return h.head;
    while(h.head -> next != nullptr)
    {
        if(h.head -> next -> points <= pont)
            return h.head;
        h.head = h.head -> next;
    }
    return nullptr;
}

void add(linkedList &h, int pont, std::string nev)
{
    if(isEmpty(h))
    {
        h.head = new itemType;
        h.head -> points = pont;
        h.head -> name = nev;
        h.head -> next = nullptr;
        h.tail = h.head;
    }
    else
    {
        itemType *t = new itemType;
        t -> points = pont;
        t -> name = nev;
        itemType *p = find(h, pont);

        if(p == h.head && h.head -> points <= t ->points)
        {
            t -> next = h.head;
            h.head = t;
        }
        else if(p == nullptr)
        {
            h.tail -> next = t;
            h.tail = t;
            t -> next = nullptr;
        }
        else
        {
            t -> next = p -> next;
            p -> next = t;
        }
    }
}

void print(linkedList h)
{

    int i=1;
    while(h.head!= nullptr && i<=3)
    {
        std::cout<<h.head -> name <<", Pontszam: "<<h.head -> points<<std::endl;
        h.head = h.head -> next;
        i++;
    }
    std::cout<<std::endl;
}
#endif //UNTITLED2_SORTEDLIST_H
