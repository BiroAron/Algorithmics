#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    int salaries[n], i, j, conditions[2]={1000, 700};
    for(int i = 0; i < n; i++)
        std::cin >> salaries[i];
    for(int h = 0; h < sizeof(conditions) / sizeof(conditions[0]); h++)
    {
        j = n - 1;
        while(i < j)
        {
            if(salaries[i] < conditions[h])
                while(j > i)
                {
                    if(salaries[j] >= conditions[h])
                    {

                        salaries[i] += salaries[j];
                        salaries[j] = salaries[i] - salaries[j];
                        salaries[i] -= salaries[j];
                        break;
                    }
                    j--;
                }
            i++;
        }
    }
    for(i = 0; i < n; i++)
    {
        if(conditions[0] > salaries[i] && conditions[0] < salaries[i-1])
            std::cout << std::endl;
        else if(conditions[1] > salaries[i] && conditions[1] < salaries[i-1])
            std::cout << std::endl;
        std::cout << salaries[i]<<' ';
    }
    return 0;
}
