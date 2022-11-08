#include <iostream>

void cut(int &number) //elso szamjegy levagasa
{
    int t = 1, numSave = number;
    while(numSave>10)
    {
        numSave /= 10;
        t = t * 10;
    }
    number %= t;
}

bool checkForValley(bool &check, int a, int b)
{
    if(check)
    {
        if(a < b)
            check = false;
        return true;
    }
    else if(a < b)
        return true;
    else
        return false;
}

bool checkForMountain(bool &check, int a, int b)
{
    if(check)
    {
        if(b < a)
            check = false;
        return true;
    }
    else if(b < a)
        return true;
    else
        return false;
}

bool isItRight(int n, bool (*F)(bool&, int, int))//fuggvenypontert hasznalok, hogy ne kelljen két teljesen külon alprogramot 1rjak a hegyszám és a völgyszámokra
{
    int a, b;
    bool check = true;
    while(n > 9)
    {
        a = n%10;
        b = (n/10)%10;
        if(!F(check, a, b))
            return false;
        n = n/10;
    }
    return true;
}

int main()
{
    int num;
    std::cin>>num;
    if(num < 101)
    {
        std::cout<<"nincs volgyszam sem hegyszam.";
    }
    else if(num%10 > (num/10)%10) //az utolso ket szamjegy relacioja szeint eldontom hogy hegyszam ellenorz;st v;gzek vagy volgyszamot
    {
        if(isItRight(num, checkForValley))
            std::cout<<"volgyszam";
         else
        {
            while(num >= 101 && !isItRight(num, checkForValley)) //az 101es hasonlitas azert van mert az a legkisebb volgyszam
                cut(num);
            if(num >= 101)
                std::cout<<num;
            else
                std::cout<<"nincs volgyszam sem hegyszam.";
        }
    }
    else if(num%10 < (num/10)%10)
    {
        if(isItRight(num, checkForMountain))
            std::cout<<"hegyszam";
        else
        {
            while(num >= 121 && !isItRight(num, checkForMountain)) //ugyan ugy, a 121es hasonlitas azert van mert az a legkisebb hegyszam
                cut(num);
            if(num >= 121)
                std::cout<<num;
            else
                std::cout<<"nincs volgyszam sem hegyszam.";
        }
    }
    return 0;
}
