//Biró Áron, Gazdasági Informatika 1.csoport, 2.feladat
#include <iostream>

using namespace std;

int main()
{
    int x, y, z;
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;
    cout << "z = ";
    cin >> z;
    if (x <= y)
    {
        if (z >= y)
            cout << x << ", " << y << ", " << z;
        if (z < x)
            cout << z << ", " << x << ", " << y;
        if (z >= x && z < y)
            cout << x << ", " << z << ", " << y;
    }
    else{
        if (z <= y)
            cout << z << ", " << y << ", " << x;
        if (z > x)
            cout << x << ", " << y << ", " << z;
        if (z <= x && z > y)
            cout << y << ", " << z << ", " << x;
    }
    return 0;
}
