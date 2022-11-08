#include <fstream>
#include <iostream>

void insSort(unsigned long long seq[], int n)
{
    for(int j = 1; j < n; j++)
    {
        unsigned long long t = seq[j];
        int i = j-1;
        while(i >= 0 && seq[i] > t)
        {
            seq[i+1] = seq[i];
            i--;
        }
        seq[i+1] = t;
    }
}

int main()
{
    int N;
    std::ifstream inputf("input.txt");
    inputf >> N;
    unsigned long long arr[N];
    for(int i = 0; i < N; i++)
        inputf >> arr[i];
    insSort(arr, N);
    for(int i = 0; i < N; i++)
        std::cout << arr[i] << " ";
    return 0;
}
