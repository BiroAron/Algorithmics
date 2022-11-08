#include <iostream>

int main()
{
    int n, i, j, num = 0;
    std::cin >> n;
    int notes[n];
    for(int i = 0; i < n; i++)
        std::cin >> notes[i];
    i = 0;
    j = n-1;
    while(i < j)
    {
        if(notes[i] < 5)
            while(j > i)
            {
                if(notes[j] >= 5)
                {

                    notes[i] = notes[j];
                    j--;
                    num++;
                    break;
                }
                j--;
            }
        else
            num++;
        i++;
        }
    for(j = 0; j < num; j++)
        std::cout << notes[j] << ' ';
    return 0;
}
