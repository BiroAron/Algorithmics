#include <iostream>
#include "doublylinkedlist.h"

int main()
{
    dlList lista;
    init(lista);
    std::string str;
    std::cout<<"Hogy a szavak beolvasasa megkezdodjon, irjon egy '*' karakert,\na beolvasas befejezesehez pedig ujra irja be a '*' karaktert.\n";
    std::cin>>str;
    while(str != "*")
    {
        std::cout<<"Nem csillag(*) karaktert adott meg a szavak beolvasasa nem kezdodott el.\n";
        std::cout<<"Probalja ujra:";
        std::cin>>str;
    }

    lista.head -> data = str;
    std::cout<<"Adja meg az elso szavat:";
    std::cin>>str;
    add(lista, str);

    while(str!="*")
    {
        std::cout<<"Kovetkezo:";
        std::cin>>str;

        if(str=="*")
        {
            lista.tail -> data = str;
            break;
        }
        else
            add(lista, str);

        std::cout<<"A lista beolvasasi sorrendben: ";
        print(lista);

        std::cout<<"A lista forditott sorrendben: ";
        printReverse(lista);
    }
    return 0;
}
