#include <bits/stdc++.h>
using namespace std;
long long n;
int main()
{
    cin>>n;
    for (long long i=1;i<=n; i++)
    {
        for (long long j=1;j<=i; j++)
        cout<<"*";
        cout<<endl;
    }
}

