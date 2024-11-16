#include <bits/stdc++.h>
using namespace std;
long long a[1000][1000],s,n,i,j;
int main()
{
    ios::sync_with_stdio;
        cin.tie(0);
        cout.tie(0);
    cin>>n; s=0;
    for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    cin>>a[i][j];
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        s=s+a[i][j];
    }
    cout<<s;
}

