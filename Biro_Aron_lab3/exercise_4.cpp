#include <fstream>
#include <iostream>

void binSort(unsigned long long seq[], unsigned long long seq2[], int n, int t[], unsigned long long k, unsigned long long mini)
{
    for(int i = 0; i < n; i++)
        t[seq[i] - mini]++;
    for(unsigned long long i = 1; i <= k; i++)
        t[i] += t[i-1];
    for(int j = n-1; j >= 0; j--)
    {
        seq2[t[seq[j] - mini]] = seq[j];
        t[seq[j] - mini]--;
    }
}

int main()
{
    int N;
    std::ifstream inputf("input.txt");
    inputf >> N;
    unsigned long long arr[N], arr2[N] = {0}, maxi, mini;
    inputf >> arr[0];
    maxi = mini = arr[0];
    for(int i = 1; i < N; i++)
    {
        inputf >> arr[i];
        if(arr[i] > maxi)
            maxi = arr[i];
        else if(arr[i] < mini)
            mini = arr[i];
    }
    int h[maxi-mini] = {0};
    binSort(arr, arr2, N, h, maxi-mini, mini);
    for(int i = 1; i <= N; i++)
        std::cout << arr2[i] << " ";
    inputf.close();
    return 0;
}
