#include <bits/stdc++.h>
#define simon "recmin"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define cc pair<char, char>
using namespace std;
const int N=1e3+5;
const int M=2e2+5;
const ll oo=1e15;
const int MOD=123456789;

int m, n, ans=INT_MAX;
ll k, a[M][N], b[M][N];

int main(){
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    FASTio
    cin >> m >> n >> k;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            cin >> a[i][j];

    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            b[i][j]=b[i-1][j]+a[i][j];

    for (int i=1; i<=m; i++){
        for (int j=i; j<=m; j++){
            int l=1;
            ll s=0;
            for (int r=1; r<=n; r++){
                s+=b[j][r]-b[i-1][r];
                while ( s >= k ){
                    if ( s == k ) ans=min(ans, (j-i+1)*(r-l+1));
                    s-=b[j][l]-b[i-1][l];
                    l++;
                }
            }
        }
    }

    if ( ans==INT_MAX ) cout << -1;
    else cout << ans;
    return 0;
}
