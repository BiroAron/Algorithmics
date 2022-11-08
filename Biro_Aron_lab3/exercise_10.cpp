#include <iostream>

using namespace std;

float sqrt(int a, int i)
{
    if(i == 6)//5 tizedes pontossagig megy (10^-6)
        return a;
    else
        return ((sqrt(a, i+1) + a/sqrt(a, i+1))/2);
}

int main()
{
    int a;
    std::cin >> a;
    std::cout << sqrt(a, 0);
    return 0;
}
