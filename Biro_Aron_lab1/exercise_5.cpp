//Biró Áron, Gazdasági Informatika 1.csoport, 5.feladat
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float a, b, c, delta;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    delta = b * b - (4 * a * c);
    if (delta < 0)
        cout << "Az egyenletnek nincs valos megoldasa";
    if (delta == 0)
        cout << "Megoldas: " << -b / (2 * a);
    if (delta > 0)
        cout << "Megoldasok: " << (-b - sqrt(delta)) / (2 * a) << ", " << (-b + sqrt(delta)) / (2 * a);
    return 0;
}
