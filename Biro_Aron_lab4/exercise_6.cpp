//Biró Áron, Gazdasági Informatika 1.csoport, 6.feladat

#include <iostream>

using namespace std;

void hanoi_t(int n, char a, char b, char c)
{
    if(n==1)
        cout<<"Az 1. korongot az "<<a<<" rudrol a "<<b<<" rudra tesszuk."<<endl;
    else
    {
        hanoi_t(n-1, a, c, b);
        cout<<"Az "<<n<<". korongot az "<<a<<" rudrol a "<<b<<" rudra tesszuk."<<endl;
        hanoi_t(n-1, c, b, a);
    }
}

int main()
{
    int n;
    cout<<"n = "; cin >> n;
    hanoi_t(n, 'A', 'B', 'C');
    return 0;
}
