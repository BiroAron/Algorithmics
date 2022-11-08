#include <iostream>

int convert(char c) //atalakitom charbol a szamokat es a-tol e-ig a betuket (kicsit es nagyont is) integerekke
{
    if(c >= 'A' && c <= 'E')
        return c - 55;
    else if(c >= 'a' && c <= 'e')
        return c - 87;
    else
        return c - 48;
}

int pow(int power)//hatvanyozas
{
    if(power == 0)
        return 1;
    else
        return 16 * pow(power - 1);
}

int convertHexToDec(std::string a, int length, int i)
{
    if(a[i+1] == '\0')//ha a sstring vegen vagyunk
        return pow(length-(i+1)) * convert(a[i]);
    else//minden mas eset
        return pow(length-(i+1)) * convert(a[i]) + convertHexToDec(a, length, i+1);
}

int main()
{
    std::string a;
    getline(std::cin, a);
    int t = 1, len = a.length();
    if(a[0]=='-') //mukodik negativ szamokra is
    {
        t=-1;
        for(int i=1; i <= len; i++)
            a[i-1] = a[i];
        len--;
        a[len]='\0';
    }
    t *= convertHexToDec(a, len, 0);
    std::cout << t;
    return 0;
}
