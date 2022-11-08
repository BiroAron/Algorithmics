#include <iostream>

int NumOfSteps(int number) //megsz�molja h�ny l�p�sb�l lehet egy sz�mb�l eljutni az egyeshez az adott m�dszerrel
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
    if(a > b) //arra az esetre ha a hat�rok forditva lenn�nek megadva
    {
        a += b;
        b = a - b;
        a -= b;
    }
    for(int i = a; i <= b; i++)
    {
        i_step = NumOfSteps(i);
        if(i_step >= maxstep) //maximumkiv�laszt�s a leghosszabb l�p�ssz�m szerint
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
