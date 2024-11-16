#include <bits/stdc++.h>
using namespace std;
long long x,k,d;
int main()
{
    cin>>x>>k>>d;
    x=abs(x);
    long long e=x/d;
    long long y=x%d;
    if (k<=e) cout <<x-k*d;
    else
    {
        long long f=k-e;
        if (f%2==0) cout<<y;
        else cout<<d-y;
    }
}
