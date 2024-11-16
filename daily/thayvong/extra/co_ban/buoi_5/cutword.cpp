#include <bits/stdc++.h>
using namespace std;
long long x,y;
int main()
{
    cin>>x>>y;
    long long z=min(x,y);
    for (long long i=z; i>=1; i--)
    if (x % i==0 && y % i==0)
    {
        cout<<i;
        break;
    }
}
