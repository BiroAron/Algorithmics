#include <iostream>

int SmallestDivisor(int num) //meghatárzza egy szám legkisebb osztóját
{
	if (num % 2 == 0) //ha a szám páros akkor egyértelmûen a legkisebb osztó az a 2
			return 2;
    else
        for(int i = 3; i * i <= num; i += 2) //megyünk a szám gyökéig és nezzük hogy van-e osztó
            if(num % i == 0)
                return i;
	return num; //ha nem találtunk a gyökig osztót akkor a szám prímszám és az egyetel egytõl különbözõ osztója az önmaga
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
