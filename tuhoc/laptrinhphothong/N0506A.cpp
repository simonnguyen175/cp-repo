#include <bits/stdc++.h>
using namespace std;
long long n,i,j,a[1000][1000],s;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n; s=0;
    for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    cin>>a[i][j];
    for (i=1;i<=n;i++) s=s+a[i][i];
    cout<<s;
}
