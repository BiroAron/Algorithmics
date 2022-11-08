#include <iostream>
#include "sortedlist.h"

int main() {
    linkedList h;
    init(h);
    int pont;
    std::string nev;

    std::cout<<"Adja meg az ugrok nevet, majd pontszamat, (mindegyik utan <enter>). \nHa nincs tobb versenyzo irjon be egy 'x' karatert a \"Kovetkezo versenyzo: \" megadasa helyett\n";

    std::cout<<"Elso ugro:";
    std::cin>>nev;
    if(nev == "Befejez")
        return 0;
    std::cout<<"Pontszama:";
    std::cin>>pont;
    add(h, pont, nev);
    std::cout<<std::endl;

    print(h);

    while(nev != "Befejez")
    {
        std::cout<<"Kovetkezo ugro:";
        std::cin >> nev;
        std::cin.clear();
        if(nev == "Befejez")
            return 0;
        std::cout<<"Pontszama:";
        std::cin>>pont;
        std::cin.clear();

        add(h, pont, nev);
        std::cout<<std::endl;
        print(h);
    }

    /*add(h, 12, "Nicolas Cage");
    add(h, 13, "Jezus");
    add(h, 10, "Ferenc papa");
    add(h, 11, "Vekov Geza");
    add(h, 2147483647, "Cuck Norris");
    print(h);*/
    return 0;
}
