//Biró Áron, Gazdasági Informatika 1.csoport, 9.feladat
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
	float a, b, c, p, T;
	cin >> a;
	cin >> b;
	cin >> c;
	if ((a >= (b + c)) || (b >= (a + c)) || (c >= (a + b)))
		cout << "Nem alkothatnak haromszoget.";
	else
	{
		p = (a + b + c) / 2;
		T = sqrt(p * (p - a) * (p - b) * (p - c));
		cout << "A haromszogbe irhato kor sugara: " << fixed << setprecision(3) << 2 * T / (a + b + c) << endl;
        cout << "A haromszog kore irhato kor sugara: " << fixed << setprecision(3) << (a * b * c) / (4*T);
	}
}
