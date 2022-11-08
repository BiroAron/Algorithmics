//
// Created by Aaron on 2021. 01. 17..
//

#ifndef INC_2_FELADAT_STATICLIST_H
#define INC_2_FELADAT_STATICLIST_H

#define size 3

typedef std::string custom;

struct staticStackType{
    int head;
    custom items[size];
};

void statInit(staticStackType &h)
{
    h.head = -1;
}

bool isEmptyStatic(staticStackType &h)
{
    return h.head == -1;
}

bool isFull(staticStackType &h)
{
    return h.head == size-1;
}

void addStatic(staticStackType &h, custom d)
{
    h.head++;
    h.items[h.head] = d;
}

void del(staticStackType &h, custom d)
{
    for(int j = h.head; j>=0; j--)
    {
        if(d == h.items[j])
        {
            h.items[j] = h.items[h.head];
            h.head--;
            return;
        }
    }
    std::cout<<"Nem tavozhat az adott ember ha meg sem erkezett!";
}

void printStatic(staticStackType &h)
{
    std::cout<<"A boltban levo emberek: ";
    for(int i=0; i<=h.head; i++)
    {
        if(i!=h.head)
            std::cout<<h.items[i]<<", ";
        else
            std::cout<<h.items[i];
    }
    std::cout<<std::endl;
}

#endif //INC_2_FELADAT_STATICLIST_H
