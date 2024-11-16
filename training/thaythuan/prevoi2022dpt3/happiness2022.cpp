#include<bits/stdc++.h>
#define ll long long
#define BIT(x, k) ((x>>k)&1)
using namespace std;
const int N = 21;

int n, h;
int a[N], b[N];
ll fa[1<<N], sb[1<<N];

void solve(){
    cin >> n >> h;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        cin >> b[i];

    for (int i = 0; i < (1<<n); i ++){
        ll s = 0;
        sb[i] = 0;
        for (int j = 1; j <= n; j ++) if ( BIT(i, j-1) ){
            s += a[j];
            sb[i] += b[j];
        }
        fa[i] = ( s >= h );
    }

    for (int j = 0; j < n; j ++)
    for (int i = (1<<n)-1; i >= 1; i --) if ( BIT(i, j) )
        fa[i^(1<<j)] += fa[i];

    ll ans = 0;

    for (int i = 0; i < (1<<n); i ++)
        if ( sb[i] >= h ) ans += fa[((1<<n)-1)^i];

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
