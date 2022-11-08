//Biró Áron, Gazdasági Informatika 1.csoport, 2.feladat

#include <iostream>
#include <fstream>

using namespace std;

void print(char op[], int x[], int n)
{
    for(int i=0; i<n; i++)
    {
        if(i<n-1)
            cout<<x[i]<<op[i];
        else
            cout<<x[i];
    }
    cout<<endl;
}

void choose(char op[], int i, int j)
{
    if(j==0)
        op[i]='+';
    else if(j==1)
        op[i]='-';
    else if(j==2)
        op[i]='*';
    else
        op[i]='/';
}

bool fits(char op[], int x[], int n, int K)
{
    int ossz = x[0];
    for(int i=1; i<n; i++)
    {
        if(op[i-1]=='+')
            ossz += x[i];
        else if(op[i-1]=='-')
            ossz -= x[i];
        else if(op[i-1]=='*')
            ossz *= x[i];
        else
            ossz /= x[i];
    }
    if(ossz == K)
        return true;
    return false;
}

int sum(int x[], char op[], int i)
{
    int ossz=x[0];
    for(int j=1; j<i; j++)
    {
        if(op[i-1]=='+')
            ossz += x[i];
        else if(op[i-1]=='-')
            ossz -= x[i];
        else if(op[i-1]=='*')
            ossz *= x[i];
        else
            ossz /= x[i];
    }
    return ossz;
}

bool check(char op[], int x[], int i)
{
    float t;
    if(i==0)
        return true;
    else if((x[i]==0 && op[i-1] == '/') || (op[i-1]=='/' && (float)sum(x, op, i)/(float)x[i] != sum(x, op, i)/x[i]))
        return false;
    return true;
}

void operations(int i, char op[], int n, int x[], int K, int &c)
{
    for(int j=0; j<4; j++)
    {
        choose(op, i, j);
        if(check(op, x, i))
            if(i<n-1)
                operations(i+1, op, n, x, K, c);
            else
                if(fits(op, x, n, K))
                {
                    c++;
                    print(op, x, n);
                    break;
                }
    }
}

int main()
{
    ifstream f("input.txt");
    int n, K, c=0;
    f>>n;
    int x[n];
    char op[n-1]={' '};
    for(int i=0; i<n; i++)
        f>>x[i];
    f>>K;
    operations(0, op, n, x, K, c);
    if(c==0)
        cout<<"Nem letezik megoldas!";
    f.close();
    return 0;
}
