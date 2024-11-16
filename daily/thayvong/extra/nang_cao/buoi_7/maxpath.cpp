#include <bits/stdc++.h>
using namespace std;

int n,m;
long long a[1001][1001], s[1001][1001];

int main(){
    freopen("maxpath.inp","r",stdin);
    freopen("maxpath.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> m >> n ;
    for (int i=1; i<= m; i++)
        for (int j=1; j <=n; j++)
            cin >> a[i][j];

    s[1][1] = a[1][1];
    for (int i=2; i<=n; i++)
        s[1][i]= s[1][i-1]+a[1][i] ;
    for (int i=2; i<=m; i++)
        s[i][1]= s[i-1][1]+a[i][1];
    for (int i=2; i<=m; i++)
        for (int j=2; j<=n; j++)
            s[i][j]=max(s[i-1][j],s[i][j-1])+a[i][j];
    cout << s[m][n];
    return 0;
}
