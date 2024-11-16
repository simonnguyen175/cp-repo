#include<bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 5e3 + 5;

int n;
pi a[N];
ll f[N][N];

void ckmn(ll &a, ll b){
    if ( a == -1 ) a = b;
    else a = min(a, b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("sortwood.inp", "r", stdin);
    freopen("sortwood.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].fi >> a[i].se;

    sort(a + 1, a + 1 + n, [&](pi &x, pi &y){
        if ( x.fi + x.se == y.fi + y.se ) return x.fi < y.fi;
        else return x.fi + x.se < y.fi + y.se;
    });

    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= n; j ++)
        f[i][j] = -1;

    f[0][0] = 0;
    for (int i = 0; i < n; i ++)
    for (int j = 0; j <= i; j ++) if ( f[i][j] != -1 ){
        ckmn(f[i+1][j], f[i][j]);
        if ( f[i][j] <= a[i+1].fi ) ckmn(f[i+1][j+1], f[i][j] + a[i+1].se);
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++) if ( f[n][i] != -1 )
        ans = i;

    cout << ans;

    return 0;
}
