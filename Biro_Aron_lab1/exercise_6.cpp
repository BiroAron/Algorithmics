//Biró Áron, Gazdasági Informatika 1.csoport, 6.feladat
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
    float a, b, c;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    float p = (a + b + c) / 2;
    cout << fixed << setprecision(2) << sqrt(p * (p - a) * (p - b) * (p - c));
    return 0;
}
