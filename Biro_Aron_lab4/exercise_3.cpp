//Biró Áron, Gazdasági Informatika 1.csoport, 3.feladat

#include <iostream>
#include <fstream>

using namespace std;

 struct shape{
    string colour;
    int s;
    int id;
};

void print(shape sol_square[], int k)
{
    for(int i=0; i<k; i++)
        cout<<sol_square[i].id<<' ';
    cout<<endl;
}

bool check(int i, int j, shape square[], shape sol_square[])
{
    if(i==0)
        return true;
    else if(sol_square[i-1].colour == sol_square[i].colour || sol_square[i-1].s < sol_square[i].s)
        return false;
    return true;
}

void tower(shape square[], int i, int k, int num, shape sol_square[])
{
    for(int j=0; j<num; j++)
    {
        sol_square[i]=square[j];
        if(check(i, j, square, sol_square))
        {
            if(i<k-1)
                tower(square, i+1, k, num, sol_square);
            else
                print(sol_square, k);
        }
    }
}

int main()
{
    ifstream f("input.txt");
    int num, k;
    f>>num>>k;
    shape square[num], sol_square[k];
    int i=0;
    while(!f.eof())
    {
        f>>square[i].colour;
        f>>square[i].s;
        square[i].id = i+1;
        i++;
    }
    tower(square, 0, k, num, sol_square);
    f.close();
    return 0;
}
