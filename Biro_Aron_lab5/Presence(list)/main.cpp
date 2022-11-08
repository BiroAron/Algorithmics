#include <iostream>
#include <string>
#include "feladat1_header1.h"

using namespace std;

int main() {

    list *sor;
    init(sor);
    string a;

    cout<<"Ha hozzaadna egy nevet a listahoz irja azt be,\nha ki szeretne lelpni a programbol a kovetkezo olvasasnal az \"Kilep\" szavat olvassa be."<< endl;
    cout<<"Elso elem:";

    cin >> a;

    while(a != "Kilep" && a != "kilep")
    {
        list *t = WhereIsIt(sor, a);
        if(t == nullptr)
            push(sor, a);
        else if(t == sor)
            pop(sor);
        else
            del(sor, a);
        print(sor);
        cout<<"Kovetkezo elem:";
        cin >> a;
    }
    return 0;
}
