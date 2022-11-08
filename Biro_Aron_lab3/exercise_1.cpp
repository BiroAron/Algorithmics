#include <fstream>
#include <iostream>

void bubbleSort(unsigned long long sec[], int n)
{
    bool ok;
    int k = n;
    do {
        n = k;
        ok = false;
        for(int i=0; i < n; i++)
            if (sec[i] > sec[i + 1])
            {
                ok = true;
                unsigned long long t = sec[i];
                sec[i] = sec[i + 1];
                sec[i + 1] = t;
                k = i;
            }
    }while(ok);
}

int main()
{
    int N;
    std::ifstream inputf("input.txt");
    inputf >> N;
    unsigned long long arr[N];
    for(int i = 0; i < N; i++)
        inputf >> arr[i];
    bubbleSort(arr, N-1);
    for(int i = 0; i < N; i++)
        std::cout << arr[i] << " ";
    inputf.close();
    return 0;
}
