#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int M = 15005;
const int N = 1505;

int m, n, ans = 0, cost = 1e9;
int cell[M][N], s[N];
vector<pi> a[2];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("pbcrect.inp", "r") ){
        freopen("pbcrect.inp", "r", stdin);
        freopen("pbcrect.out", "w", stdout);
    }

    cin >> m >> n;

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++){
        char x; cin >> x;
        if ( x == '1' ) cell[i][j] = 1;
        else cell[i][j] = 0;
    }

    for (int i = 1; i <= n; i ++) a[0].pb({0, i});

    for (int i = 1; i <= m; i ++){
        int t = i%2;
        a[t].clear();

        for (int j = 0; j < n; j ++){
            if ( cell[i][a[1-t][j].se] )
                a[t].pb({++a[1-t][j].fi, a[1-t][j].se});
            else a[1-t][j].fi = 0;
        }

        for (int j = 0; j < n; j ++)
            if ( a[1-t][j].fi == 0 )
                a[t].pb({0, a[1-t][j].se});

        int tmp = 0, cur = 1e9, pos;
        for (int j = 1; j <= n; j ++)
            if ( tmp <= a[t][j-1].fi * j )
                tmp = a[t][j-1].fi * j, pos = j;

        if ( ans > tmp ) continue;

        for (int j = 1; j <= n; j ++) s[j] = 0;
        for (int j = 1; j <= pos; j ++) s[a[t][j-1].se] = 1;
        for (int j = 1; j <= n; j ++) s[j] += s[j-1];

        for (int j = pos; j <= n; j ++) cur = min(cur, pos - s[j] + s[j-pos]);

        if ( ans < tmp ) ans = tmp, cost = cur;
        else if ( ans == tmp && cost > cur ) cost = cur;
    }



    cout << ans << '\n' << cost;

    return 0;
}
