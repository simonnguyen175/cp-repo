#include <bits/stdc++.h>
using namespace std;
long long a[1000][1000],n,i,j;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n;
    for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    cin>>a[i][j];
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        cout<<a[i][j]<<" ";
        cout<<"\n";
    }
}