//Biró Áron, Gazdasági Informatika 1.csoport, 8.feladat
#include <iostream>

using namespace std;

int main()
{
	int h[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char szdatum[11], maidatum[11];
	int napszam = 0, t = 0;
	cout << "elso: ";
	cin >> szdatum;
	cout << "masodik: ";
	cin >> maidatum;

	///struktûra deklarálása amelybe átalakítom a dátumot aktuális számokká
	struct datum {
		int nap;
		int honap;
		int ev;
	}datum1, datum2;
	datum1 = datum2 = { 0, 0, 0 };

	///átalakítás
	for (int i = 0; i <= 9; i++)
	{
		if (i <= 3 && i >= 0)
		{
			datum1.ev *= 10;
			datum1.ev += szdatum[i] - '0';
			datum2.ev *= 10;
			datum2.ev += maidatum[i] - '0';

		}
		if (i <= 6 && i >= 5)
		{
			datum1.honap *= 10;
			datum1.honap += szdatum[i] - '0';
			datum2.honap *= 10;
			datum2.honap += maidatum[i] - '0';
		}
		if (i <= 9 && i >= 8)
		{
			datum1.nap *= 10;
			datum1.nap += szdatum[i] - '0';
			datum2.nap *= 10;
			datum2.nap += maidatum[i] - '0';
		}
	}

	//ez a rész az eveket alakitja napokká
	if (datum1.ev != datum2.ev)
	{
		for (int i = datum1.ev + 1; i < datum2.ev; i++)
			if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
				napszam += 366;
			else
				napszam += 365;
	}
	//ez a rész hónapokat alakitja napokká
	if (datum1.ev != datum2.ev)//ez az ág azzal az esettel foglakozik amelyben a két dátum nem ugyan abban az évben van
	{
	    //1.dátum hónapjainak átalakítása
		for (int i = 1; i < datum1.honap; i++)
				t += h[i];
		if ((datum1.ev % 4 == 0 && datum1.ev % 100 != 0) || datum1.ev % 400 == 0) //ha szökõévben vagyunk
		{
			napszam += 366 - t;
			if (datum1.honap >= 3)
				napszam--;
		}
		else
			napszam = 365 - t;
        //2.dátum hónapjainak átalakítása
		for (int i = 1; i < datum2.honap; i++)
			napszam += h[i];
		if (((datum2.ev % 4 == 0 && datum2.ev % 100 != 0) || datum2.ev % 400 == 0) && datum2.honap >= 3)
			napszam++;
	}
	else //ez az ágg azzal az esettel foglalkozik amelynél ugyan abban az évben van a két dátum
	{
		for (int i = datum1.honap; i < datum2.honap; i++)
			napszam += h[i];
		if (((datum1.ev % 4 == 0 && datum1.ev % 100 != 0) || datum1.ev % 400 == 0) && datum1.honap <= 2)
			napszam++;
		if (datum1.honap == 2 && datum1.nap == 29)
			napszam--;
	}

	//itt a napokat is hozzáadja a változóhoz
	napszam += -datum1.nap + 1  + datum2.nap;
	cout << napszam << " nap";
	return 0;
}
