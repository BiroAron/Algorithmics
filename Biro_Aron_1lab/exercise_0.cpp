//Biró Áron, Gazdasági Informatika 1.csoport, 0.feladat
#include <iostream>
#include <iomanip>

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
    cout << "osszeg: " << x + y + z << endl;
    cout << "szorzat: " << x * y * z << endl;
    cout << "atlag: " << fixed << setprecision(2) << ((float)x+(float)y+(float)z)/3;
    return 0;
}
