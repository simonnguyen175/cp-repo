#include<bits/stdc++.h>
#define BIT(x, k) ((x>>k)&1)
#define pb push_back
#define ll long long
using namespace std;
const int N = 1e3 + 5;
const ll oo = 1e12;

int r, c, k;
int a[N][5], v[N][1<<4];
vector<int> g[1<<4];
ll f[2][2*N][1<<4];

bool check(int x){
    for (int i = 1; i < c; i ++)
        if ( BIT(x, i) && BIT(x, i-1) )
            return false;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("jump.inp", "r") ){
        freopen("jump.inp", "r", stdin);
        freopen("jump.out", "w", stdout);
    }

    cin >> r >> c >> k;
    for (int i = 1; i <= r; i ++)
    for (int j = 1; j <= c; j ++)
        cin >> a[i][j];

    for (int i = 0; i < (1<<c); i ++)
    for (int j = 0; j < (1<<c); j ++)
        if ( !(i&j) && check(j) ) g[i].pb(j);

    for (int i = 1; i <= r; i ++)
    for (int t = 0; t < (1<<c); t ++)
    for (int j = 0; j < c; j ++)
        if ( BIT(t, j) ) v[i][t] += a[i][j+1];

    for (int i = 0; i <= k; i ++)
    for (int j = 0; j < (1<<c); j ++)
        f[0][i][j] = f[1][i][j] = -oo;

    f[0][0][0] = 0;

    for (int i = 0; i < r; i ++)
    for (int j = 0; j <= k; j ++)
    for (int t = 0; t < (1<<c); t ++) if ( f[i%2][j][t] != -oo ){
        for (int nt : g[t]){
            int add = __builtin_popcount(nt);
            if ( j + add <= k )
                f[(i+1)%2][j+add][nt] = max(f[(i+1)%2][j+add][nt], f[i%2][j][t] + v[i+1][nt]);
        }
    }

    ll ans = -oo;
    for (int t = 0; t < (1<<c); t ++)
        ans = max(ans, f[r%2][k][t]);

    cout << ans;

    return 0;
}
