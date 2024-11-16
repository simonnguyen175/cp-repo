#include <bits/stdc++.h>
using namespace std;
long long a,b,dem1,dem2,dem3;
bool nto(long long x)
{
    if (x<=1) return false;
    else
    {
        for (long long i=2; i<= (int)sqrt(x); i++)
            if (x % i==0) return false;
        return true;
    }
}
bool cp(long long x)
{
    if (sqrt(x)==(int)sqrt(x)) return true;
    else return false;
}
int main()
{
    cin>>a>>b;
    for (long long i=a; i<=b; i++ )
    {
        if (nto(i)==true) dem1++;
        if (cp(i)==true) dem2++;
    }
    cout<<dem2<<" "<<dem1<<" "<<b-a+1-dem1-dem2;
}
