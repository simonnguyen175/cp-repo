#include <bits/stdc++.h>
#define simon "SubRectMax"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define cc pair<char, char>
using namespace std;
const int N=5e2+5;
const ll oo=1e15;
const int MOD=123456789;

int m, n;
ll a[N][N], b[N][N];

int main(){
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    FASTio
    cin >> m >> n;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            cin >> a[i][j];

    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            b[i][j]=b[i-1][j]+a[i][j];
    ll ans=INT_MIN;
    for (int i=1; i<=m; i++){
        for (int j=i; j<=m; j++){
            ll nn=0, s=0;
            for (int r=1; r<=n; r++){
                s+=b[j][r]-b[i-1][r];
                ans=max(ans, s-nn);
                nn=min(nn, s);
            }
        }
    }
    cout << ans;
    return 0;
}
