#include <iostream>

bool isPrime(int num, int i)/// a legnagyobb prim amire mukodik az a 43159 ha divder valtozot egyenkent novelem, ha a használom a primalgoritmust akkor 513781
{
    if(i*i > num)
        return true;
    else if(num%i == 0)
        return false;
    else
        return isPrime(num, i+1);
}

int prime(int num) //primalgoritmus hogy az osztokkal ne egyenkent kelljen lepkedni, es igy nagyobb szamokra is mukodik
{
    if(isPrime(num, 2))
        return num;
    else
        return prime(num+1);
}

void print(bool &isItTheFirstDivider, int numOfDividers, int divider) //ez azért van mert hanem a divede alprogramben 3 helyen benne kellene legyen, és kicsit sokanak találtam
{
    if(!isItTheFirstDivider)
            std::cout<<'*';
        else
            isItTheFirstDivider = false;
        if(numOfDividers > 1)
            std::cout<<divider<<'^'<<numOfDividers;
        else
            std::cout<<divider;
    return;
}

void divide(int num, int divider, int numOfDividers, bool isItTheFirstDivider)
{
    if (num == 1) //alapeset
    {
        print(isItTheFirstDivider, numOfDividers, divider);
        return;
    }
    else if(num%divider == 0) //az az eset ha egy oszto tobbszor fordul elo
    {
        numOfDividers++;
        num /= divider;
    }
    else if (numOfDividers >=1) //ha nincs tobb az adott osztobol kiiratok
    {
        print(isItTheFirstDivider, numOfDividers, divider);
        numOfDividers = 0;
        divider = prime(divider+1);
    }
    else //ha nem oszthato tobbe egy adott primmel a szam, es kiirattam akkor johet a kovi prim
        divider = prime(divider+1);
    divide(num, divider, numOfDividers, isItTheFirstDivider);
}

int main()
{
    int n;
    std::cin >> n;
    if(n <= 1) //ha a bemenet esetleg nem megfelelo
    {
        std::cout << n;
        return 0;
    }
    divide(n, 2, 0, true);
    return 0;
}
