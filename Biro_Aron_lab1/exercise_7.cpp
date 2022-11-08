//Biró Áron, Gazdasági Informatika 1.csoport, 7.feladat
#include <iostream>

using namespace std;

int main()
{
    int elso, masodik, szokoev1, drb=0;
    cout << "Elso ev: ";
    cin >> elso;
    cout << "Masodik ev: ";
    cin >> masodik;
    for (int i = elso; i <= masodik; i++)
        if ((i%4==0 && i%100!=0) || i%400==0)
        {
            szokoev1 = i;
            break;
        }
    for (int i = szokoev1; i <= masodik; i += 4)
    {
        drb++;
        if (i%100==0 && i%400!=0)
            drb--;
    }
    cout << drb;
    return 0;
}
