#include <iostream>
#include "queue.h"
#include "staticlist.h"

int main() {
    queue sor;
    init(sor);

    staticStackType bolt;
    statInit(bolt);

    std::cout<<"Egy ember hozzaadasa/eltavolitasa a listahoz/sorhoz: \"<nev> 1(hozzaadas)/-1(eltavolitas)\" (pl: Andras, 1)\n(A bolt jelenleg harom ferohelyes!)\n";
    std::string str;
    std::cin>>str;
    int d;
    std::cin>>d;

    while(true)
    {
        if(d == 1)
        {
            if (!isFull(bolt))
                addStatic(bolt, str);
            else
                enqueue(sor, str);
        }
        else if(d == -1)
        {
            del(bolt, str);
            if(!isEmpty(sor))
            {
                addStatic(bolt, sor.head->data);
                dequeue(sor);
            }
            else if(isEmptyStatic(bolt))
                break;
        }

        printStatic(bolt);
        print(sor);

        std::cin>>str;
        std::cin>>d;
    }
    return 0;
}
