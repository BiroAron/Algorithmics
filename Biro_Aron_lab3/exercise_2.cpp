#include <fstream>
#include <iostream>

void minSort(unsigned long long seq[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int minInd = i;
        for(int j = i + 1; j < n; j++)
            if(seq[minInd] > seq[j])
                minInd = j;
        unsigned long long t = seq[i];
        seq[i] = seq[minInd];
        seq[minInd] = t;
    }
}

int main()
{
    int N;
    std::ifstream inputf("input.txt");
    inputf >> N;
    unsigned long long arr[N];
    for(int i=0; i<N; i++)
        inputf >> arr[i];
    minSort(arr, N);
    for(int i=0; i < N; i++)
        std::cout << arr[i] << " ";
    inputf.close();
    return 0;
}
