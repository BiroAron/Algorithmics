//Biró Áron, Gazdasági Informatika 1.csoport, 3.feladat
#include <iostream>

using namespace std;

int main()
{
    int h, sz, d;
    cout << "h = ";
    cin >> h;
    cout << "sz = ";
    cin >> sz;
    cout << "d = ";
    cin >> d;
    if (d <= (h*2 + sz*2))
        cout << (h*2 + sz*2) - d << " hosszusagu drot szukseges meg";
    else
        cout << d - (h*2 + sz*2) << " hosszusagu drot maradt meg";
    return 0;
}
