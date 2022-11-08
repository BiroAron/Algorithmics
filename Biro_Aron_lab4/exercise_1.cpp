//Biró Áron, Gazdasági Informatika 1.csoport, 1.feladat

#include <iostream>

using namespace std;

void print(int sor[], int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(sor[i] == j)
                cout<<'Q'<<' ';
            else
                cout<<'0'<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}

bool check(int sor[], bool o[], bool fa[], bool ma[], int i, int j, int n)
{
    if(!o[j] && !fa[j-i+n-1] && !ma[2*(n-1)-i-j])
    {
        o[j]=true;
        fa[j-i+n-1]=true;
        ma[2*(n-1)-i-j]=true;
        return true;
    }
    return false;
}

void q_delete(int sor[], bool o[], bool fa[], bool ma[], int i, int j, int n)
{
    o[j] = false;
    fa[j-i+n-1] = false;
    ma[2*(n-1)-i-j] = false;
}

void queen(int sor[], bool o[], bool fa[], bool ma[], int i, int n)
{
    for(int j=1; j<=n; j++)
    {
        sor[i] = j;
        if(check(sor, o, fa, ma, i, j, n))
        {
            if(i<n)
                queen(sor, o, fa, ma, i+1, n);
            else
                print(sor, n);
            q_delete(sor, o, fa, ma, i, j, n);
        }
    }
}

int main()
{
    int n;
    cout<<"n = ";
    cin>>n;

    int sor[n];
    bool o[n]={false};
    bool fa[2*n-1]={false};
    bool ma[2*n-1]={false};

    queen(sor, o, fa, ma, 1, n);
    return 0;
}
