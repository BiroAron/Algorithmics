//Biró Áron - Gazdasági informatika 1.

#include <iostream>

int main()
{
    short n;
    std::cin >> n;
    short x[n];
    int a, b, c, min1, min2;
    for(short i=0; i<n; i++)
        std::cin >> x[i];
    a = x[0];
    b = x[1];
    c = x[2];
    if(b > a)  //maxrendezes
    {
        a += b;
        b = a - b;
        a -= b;
    }
    if (c > a)
    {
        a += c;
        c = a - c;
        a -= c;
    }
    if (c > b)
    {
        b += c;
        c = b - c;
        b -= c;
    }
    min1 = c;
    min2 = b;
    for(short i = 3; i < n; i++) //maximum es minimunkivalasztas
    {
        if(x[i] > a)
        {
            c = b;
            b = a;
            a = x[i];
        }
        else if(x[i] > b)
        {
            c = b;
            b = x[i];
        }
        else if(x[i] > c)
            c = x[i];

        if(x[i] < min1)
        {
            min2 = min1;
            min1 = x[i];
        }
        else if(x[i] < min2)
            min2 = x[i];
    }
    if(min1 * min2 > b * c)
    {
        b = min1;
        c = min2;
    }
    std::cout << "a=" << a << ',' << "b=" << b << ',' << "c=" << c;
    return 0;
}
