#include<bits/stdc++.h>
#define simon "climb"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define se second
#define fi first
using namespace std;
const int N = 1e6 + 5;
const int row[] = {0, 0, 1, -1};
const int col[] = {1, -1, 0, 0};

int m, n;
int f[N];
pair<int, pair<int, int>> a[N];

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> m >> n;
    int id[m+5][n+5];

    int cnt = 0;
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++){
            int x; cin >> x;
            a[++cnt] = {x, {i, j}};
        }

    int ans = 0;
    sort(a + 1, a + 1 + m*n);

    memset(f, 0, sizeof f);
    memset(id, 0, sizeof id);

    for (int i = 1; i <= m*n; i ++){
        f[i] = 1;
        id[a[i].se.fi][a[i].se.se] = i;
    }

    for (int i = 1; i <= m*n; i ++){
        int x = a[i].se.fi, y = a[i].se.se;

        for (int k = 0; k < 4; k ++){
            int px = x + row[k], py = y + col[k];
            int j = id[px][py];
            if ( a[j].fi >= a[i].fi ) continue;
            f[i] = max(f[i], f[j]+1);
        }

        ans = max(ans, f[i]);
    }

    cout << ans;

    return 0;
}
