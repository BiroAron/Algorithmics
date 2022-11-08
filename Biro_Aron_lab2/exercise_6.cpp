#include <iostream>
#include <string>

void convertToInt(unsigned long long arr[], std::string strNumbers, int &length)
{
    length = 0;
    int i = 0;
    while(strNumbers[i] != '\0')
    {
       if(strNumbers[i] <= '9' && strNumbers[i] >= '0')
        {
            while(strNumbers[i] != ' ' && strNumbers[i] != '\0')
            {
                arr[length] *= 10;
                arr[length] += strNumbers[i] - '0';
                i++;
            }
        }
        if(strNumbers[i] == ' ')
            length++;
        i++;
    }
    length++;
    return;
}

int main()
{
    unsigned long long int arr1[50] = {0}, arr2[50] = {0}, arr3[100];
    int i = 0, j = 0, num = 0, n, m;
    std::string sequence1, sequence2;
    getline(std::cin, sequence1);
    getline(std::cin, sequence2);
    convertToInt(arr1, sequence1, n);
    convertToInt(arr2, sequence2, m);
    arr1[n] = arr2[m] = 18446744073709551615;
    while(i < n || j < m)
    {
        if(arr1[i] < arr2[j])
        {
            arr3[num] = arr1[i];
            i++;
        }
        else
            if(arr1[i] == arr2[j])
            {
                arr3[num] = arr1[i];
                i++;
                j++;
            }
        else
        {
            arr3[num] = arr2[j];
            j++;
        }
        num++;
    }
    for(i = 0; i < num; i++)
        std::cout << arr3[i] << ' ';

    return 0;
}
