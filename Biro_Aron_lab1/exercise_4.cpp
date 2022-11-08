//Biró Áron, Gazdasági Informatika 1.csoport, 4.feladat
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    string nem;
    int magassag, eletkor;
    float S;
    cout << "nem = ";
    cin >> nem;
    cout << "magassag = ";
    cin >> magassag;
    cout << "eletkor = ";
    cin >> eletkor;
    if (nem == "no")
    {
        S = 0.9 * (50 + 0.75 * ((float)magassag - 150) + ((float)eletkor - 20) / 40);
        cout << "Idealis testsuly: " << fixed << setprecision(2) << S << " kg";
    }
    else
    {
        S = 50 + 0.75 * ((float)magassag - 150) + ((float)eletkor - 20) / 40;
        cout << "Idealis testsuly: " << fixed << setprecision(2) << S << " kg";
    }
    return 0;
}
