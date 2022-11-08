//
// Created by Aaron on 2021. 01. 16..
//

#ifndef INC_2_FELADAT_QUEUE_H
#define INC_2_FELADAT_QUEUE_H

typedef std::string custom;

struct itemType1{
    custom data;
    itemType1 *next, *prev;
};

struct queue{
    itemType1 *head;
    itemType1 *tail;
};

bool isEmpty(queue h)
{
    return (h.head == nullptr);
}

void init(queue &h)
{
    h.head = nullptr;
    h.tail = nullptr;
}

void enqueue(queue &h, custom d)
{
    itemType1 *t = new itemType1;
    t -> data = d;
    t -> next = nullptr;
    if(isEmpty(h))
        h.head = t;
    else
        h.tail -> next = t;
    h.tail = t;
}

void dequeue(queue &h)
{
    itemType1 *t = h.head;
    h.head = h.head -> next;
    delete t;
}

void print(queue &h)
{
    if(h.head != nullptr)
    {
        std::cout<<"A bolt elott varakozo emberek (erkezesi sorrendben): ";
        itemType1 *t = h.head;
        while(t != nullptr)
        {
            if(t -> next == nullptr)
                std::cout<<t -> data;
            else
                std::cout<<t -> data<<", ";
            t = t -> next;
        }

        std::cout<<std::endl;
    }
}

#endif //INC_2_FELADAT_QUEUE_H
