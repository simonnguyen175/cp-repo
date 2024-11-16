#include<bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 5;

int n;
int a[3][N], nxt[3][N];
ll s[3][N];
map<ll, int> d;
pi f[N][2];

void ckmx(pi &a, pi b){
    if ( a.fi == -1 ) a = b;
    else if ( a.fi < b.fi ) a = b;
    else if ( a.fi == b.fi ) a.se = min(a.se, b.se);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n;
    for (int i = 0; i <= 1; i ++)
    for (int j = 1; j <= n; j ++){
        cin >> a[i][j];
        s[i][j] = s[i][j-1] + a[i][j];
    }

    for (int i = 1; i <= n; i ++)
        s[2][i] = s[2][i-1] + a[0][i] + a[1][i];

    for (int i = 0; i <= 2; i ++)
    for (int j = 0; j <= n+1; j ++)
        nxt[i][j] = n + 1;

    for (int i = 0; i <= 2; i ++){
        for (int j = n; j >= 0; j --){
            if ( d[s[i][j]] ) nxt[i][j] = d[s[i][j]];
            d[s[i][j]] = j;
        }
        for (int j = 0; j <= n; j ++)
            d[s[i][j]] = 0;
    }

    for (int i = 0; i <= 2; i ++)
    for (int j = n; j >= 0; j --)
        nxt[i][j] = min(nxt[i][j], nxt[i][j+1]);

    for (int i = 0; i <= n; i ++)
    for (int t = 0; t <= 1; t ++)
        f[i][t] = {-1, -1};

    int ans = 0;
    f[0][0] = {0, 0};
    for (int i = 0; i <= n; i ++)
    for (int t = 0; t <= 1; t ++) if ( f[i][t].fi != -1 ){
        int j = f[i][t].se, v = f[i][t].fi;

        ans = max(ans, v);

        if ( nxt[t][i] != n + 1 )
            ckmx(f[nxt[t][i]][t], {v + 1, j});

        if ( nxt[1-t][j] != n + 1 )
            ckmx(f[nxt[1-t][j]][1-t], {v + 1, i});

        if ( nxt[2][i] != n + 1 )
            ckmx(f[nxt[2][i]][t], {v+1, nxt[2][i]});
    }

    cout << ans;

    return 0;
}
