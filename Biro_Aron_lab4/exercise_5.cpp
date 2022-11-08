//Biró Áron, Gazdasági Informatika 1.csoport, 5.feladat

#include <iostream>
#include <fstream>
#include <limits.h>

using namespace std;

void merge_s(int l, int mid, int r, int x[])
{
    int a[mid+2];
    int b[r+2];
    for(int i=l; i<=mid; i++)
        a[i]=x[i];
    for(int i=mid+1; i<=r; i++)
        b[i]=x[i];
    a[mid+1]=INT_MAX;
    b[r+1]=INT_MAX;
    int i=l;
    int j=mid+1;
    for(int k=l; k<=r; k++)
    {
        if(a[i]<b[j])
        {
            x[k]=a[i];
            i++;
        }
        else
        {
            x[k]=b[j];
            j++;
        }
    }
}

void sort_m(int l, int r, int x[])
{
    if(l<r)
    {
        int mid = (l+r)/2;
        rendez(l, mid, x);
        rendez(mid+1, r, x);
        osszefesul(l, mid, r, x);
    }
}

int main()
{
    ifstream f("input.txt");
    int n;
    f>>n;
    int x[n];
    for(int i=0; i<n; i++)
        f>>x[i];
    rendez(0, n-1, x);
    for(int i=0; i<n; i++)
        cout<<x[i]<<' ';
    f.close();
    return 0;
}
