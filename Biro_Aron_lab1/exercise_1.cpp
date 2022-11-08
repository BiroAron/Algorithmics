//Biró Áron, Gazdasági Informatika 1.csoport, 1.feladat
#include <iostream>

using namespace std;

int main()
{
    int x = -3, y = 4;
    x += y;
    y = x - y;
    x -= y;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    return 0;
}
