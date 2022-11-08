#include <fstream>
#include <iostream>

long long russianMultip(int a, long long b)
{
    if(a == 1)//alapeset
        return b;
    else if (a%2 == 1) // ha paratlan az 'a' bekerul az osszegbe a 'b'
            return b + russianMultip(a/2, b*2);
    else // ha paros nem kerul be
        return russianMultip(a/2, b*2);
}

int main()
{
    int a;
    long long b;
    std::ifstream inputf("input.txt");
    inputf >> a >> b;
    if(a==0 || b==0)//a zeros szorzas kikuszobolese
    {
        std::cout << 0;
        return 0;
    }
    else if(a < 0 || b < 0) // ha esetleg valahogyan negativ szamok kerulnek be
    {
        std::cout<<"Sajnos csak pozitiv szamokra mukodik a szorzas.";
        return 0;
    }
    std::cout << russianMultip(a, b);
    inputf.close();
    return 0;
}
