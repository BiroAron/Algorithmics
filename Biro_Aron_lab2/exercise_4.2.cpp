#include <iostream>

int main()
{
    int n, i, j = 1, drb = 0;
    std::cin >> n;
    int t[n];
    for(int i = 0; i < n; i++)
        std::cin >> t[i];
    i = 0;
    int k = n-1;
    while(i < j)
        for(i = 0; i <= k; i++)
            if(t[i] < 5)
            {
                for(j = k; j >= i; j--)
                    if(t[j] >= 5)
                    {
                        t[i] = t[j];
                        k = j - 1;
                        drb++;
                        break;
                    }
            }
            else
                drb++;
    for(j = 0; j < drb; j++)
        std::cout << t[j] << ' ';
    return 0;
}
