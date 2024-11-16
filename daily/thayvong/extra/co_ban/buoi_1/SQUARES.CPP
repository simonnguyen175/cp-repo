#include <bits/stdc++.h>
using namespace std;
long long n;
int main()
{
    cin>>n;
    n=n*(n+1)*(2*n+1)/6;
    cout<<n%2013;
}
