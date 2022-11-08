#include <iostream>
#include "verem.h"
#include "varakozasisor.h"
#include "lista.h"

using namespace std;

int main() {
    itemType *busz, *leszallok;
    init(busz);
    init(leszallok);

    queue sor;
    initQ(sor);

    string str;

    cout<<"Adja meg az emberek nevet(keresztnev) akik a buszon tartozkodnak jelenleg: \n(legalabb egy nev es minden nev utan <enter> szukseges, na nincs tobb nev irja be hogy \"x\")\n";
    while(cin >> str && str != "x")
        push(busz, str);
    str = "\0";

    while(str != "-1")
    {
        cout<<"Megallo! Kik akarnak leszallni?\n";
        while(cin >> str && str != "x")
            push(leszallok, str);
        str = "\0";

        cout<<"Kik akarnak felszallni?\n";
        while(cin >> str && str != "x")
            enqueue(sor, str);
        str = "\0";

        while(!isEmpty(busz) && !isEmpty(leszallok))
        {
            itemType *t = keres(leszallok, busz -> data);
            if(t == nullptr)
            {
                enqueue(sor, busz -> data);
                pop(busz);
            }
            else
            {
                del(leszallok, t);
                pop(busz);
            }
        }

        if(!isEmpty(leszallok))
        {
            cout<<"Olyan szemelyek neveit is megadta akik nem tartozkodtak a buszon.\n";
            while(!isEmpty(leszallok))
                pop(leszallok);
        }

        while(!isEmpty(sor.head))
        {
            push(busz, sor.head -> data);
            dequeue(sor);
        }

        cout<<"Jelenleg a buszon vannak:\n";
        print(busz);

        if(isEmpty(busz) && isEmpty(leszallok) && isEmpty(sor.head))
        {
            cout<<"Nincs tobb ember a buszon nem megyunk tovabb.";
            return 0;
        }

        cout<<"Tovabb megy a busz? (igen = '1', nem = '-1')\n";
        cin>>str;
    }
    return 0;
}