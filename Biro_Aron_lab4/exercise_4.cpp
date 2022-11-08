//Biró Áron, Gazdasági Informatika 1.csoport, 4.feladat

#include <iostream>
#include <fstream>

using namespace std;

float quick_pow(float num, int n)
{
    if(n==0)
        return 1;
    else
        if(n%2)
            return num*quick_pow(num*num, n/2);
        else
            return quick_pow(num*num, n/2);
}

int main()
{
    ifstream f("input.txt");
    int number, power;
    f>>number>>power;
    cout<<quick_pow(number, power);
    f.close();
    return 0;
}
