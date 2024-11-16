#include <bits/stdc++.h>
using namespace std;
long long n,a[101],b[101],ln;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n; ln=0;
    for (long long i=1; i<=n; i++)
    {
        cin>>a[i];
        b[a[i]]++;
        ln=max(ln,b[a[i]]);
    }
    cout<<ln;
}

