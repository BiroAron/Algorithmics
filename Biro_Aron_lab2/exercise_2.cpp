#include <iostream>

int SmallestDivisor(int num) //meghat�rzza egy sz�m legkisebb oszt�j�t
{
	if (num % 2 == 0) //ha a sz�m p�ros akkor egy�rtelm�en a legkisebb oszt� az a 2
			return 2;
    else
        for(int i = 3; i * i <= num; i += 2) //megy�nk a sz�m gy�k�ig �s nezz�k hogy van-e oszt�
            if(num % i == 0)
                return i;
	return num; //ha nem tal�ltunk a gy�kig oszt�t akkor a sz�m pr�msz�m �s az egyetel egyt�l k�l�nb�z� oszt�ja az �nmaga
}

int main()
{
    int n;
    std::cin >> n;
    if (n == 0 || n == 1)
        std::cout << "Nincs egynel nagyobb oszto.";
    else
        std::cout << SmallestDivisor(n);
    return 0;
}
