#include <bits/stdc++.h>
using namespace std;
long long n,x,a[101],s;
int main()
{
    cin>>n>>x;
    s=0;
    for (long long i=1; i<=n; i++)
    {
        cin>>a[i];
        if (a[i]>=x) s++;
    }
    cout<<s;
}
