#include <fstream>
#include <iostream>

int pow(int n, int power) //hatvanyozas
{
    if(power == 0)
        return 1;
    else
        return n * pow(n, power - 1);
}

int polinom(int arr[], int x, int i, int n)
{
    if (i == n) //alapeset
        return arr[i];
    else  //minen mas
        return (arr[i]*pow(x, n-i) + polinom(arr, x, i+1, n));
}

int main()
{
    int n, x;
    std::ifstream inputf("input.txt");
    inputf >> n;
    int arr[n+1];
    for(int i = 0; i <= n; i++)
        inputf >> arr[i];
    inputf >> x;
    std::cout << polinom(arr, x, 0, n);
    inputf.close();
    return 0;
}
