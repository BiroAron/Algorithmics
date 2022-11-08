#include <iostream>

int NumOfSteps(int number) //megszámolja hány lépésbõl lehet egy számból eljutni az egyeshez az adott módszerrel
{
    if (number == 0) return -1;
    int steps = 0;
    while(number != 1)
    {
        if(number % 2 == 0)
            number /= 2;
        else
            number = (number * 3) + 1;
        steps++;
    }
    return steps;
}

int main()
{
    int a, b, maxstep = 0, bestnum, i_step;
    std::cin >> a;
    std::cin >> b;
    if(a > b) //arra az esetre ha a határok forditva lennének megadva
    {
        a += b;
        b = a - b;
        a -= b;
    }
    for(int i = a; i <= b; i++)
    {
        i_step = NumOfSteps(i);
        if(i_step >= maxstep) //maximumkiválasztás a leghosszabb lépésszám szerint
        {
            maxstep = i_step;
            bestnum = i;
        }
    }
    if(i_step == -1)
        std::cout << "A zerosbol nem lesz 1 ha csak szorozzuk meg osztjuk.";
    else
        std::cout << bestnum;
    return 0;
}
