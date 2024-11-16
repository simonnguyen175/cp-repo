#include <bits/stdc++.h>
using namespace std;

int n,m;
long long a[1001][1001];
long long s[1001][1001];
long long ans ;

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    freopen("Diagon1.inp","r",stdin);
    freopen("Diagon1.out","w",stdout);
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin >>  a[i][j];
    ans = a[1][1]+a[2][2] +a[3][3];
    for (int i=1; i<=n-2; i++)
        for (int j=1; j<=m-2; j++)
            ans =max(ans,a[i][j]+a[i+1][j+1]+a[i+2][j+2]);
    cout << ans;
    return 0;
}
