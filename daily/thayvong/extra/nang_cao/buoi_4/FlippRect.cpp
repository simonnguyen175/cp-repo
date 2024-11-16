#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[1001][1001];

int main(){
    freopen("FlippRect.inp","r",stdin);
    freopen("FlippRect.out", "w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    int res=0, soam=0, nn=INT_MAX ;
    cin >> n >> m ;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++){
            cin >> a[i][j];
            res+=abs(a[i][j]);
            if (a[i][j] < 0) soam++;
            nn = min(nn, abs(a[i][j]));
        }
    if ( soam % 2 == 0 ) cout << res ;
    else
            cout << res - 2*nn;
}
