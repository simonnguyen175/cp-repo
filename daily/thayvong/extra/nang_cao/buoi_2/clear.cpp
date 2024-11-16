#include <bits/stdc++.h>
using namespace std;
int n,a[10]={0,1,0,0,0,0,0,1,0,0};
int somoi (int n)
{
    int s=0,x;
    while (n>0)
    {
        x=n%10;
        s+=(x*x);
        n/=10;
    }
    return s;
}
int main()
{
    freopen("clear.inp","r",stdin);
    freopen("clear.out","w",stdout);
    while (cin >> n)
    {
        while (n>9) n=somoi(n);
        cout << a[n] <<"\n";
    }
}
