#include<bits/stdc++.h>
using namespace std;
long long n,k;
int main()
{
    cin>>n>>k;
    if (k>n) cout<<n*(n+1)/2;
    else cout<<(n-k)*k+k*(k+1)/2;
}

