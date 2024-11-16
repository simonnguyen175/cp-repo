#include <bits/stdc++.h>
using namespace std;
long long n;
int main()
{
    cin>>n;
    if (n<=1) {cout<<0; return 0;}
    for (long long i=2;i<=(int)sqrt(n); i++)
    {
        if  (n%i==0) {cout<<0; return 0;}
    }
    cout<<1;
    return 0;
}

