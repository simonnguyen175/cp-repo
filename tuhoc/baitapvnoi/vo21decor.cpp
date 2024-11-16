#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 5e5 + 5;

int n, m, k, nn = 0;
int a[N], s[N], id[N];
vector<int> g[N];

void dfs(int u){
    if ( a[u] ) s[nn] --;
    id[u] = nn;
    for (int v : g[u])
        if ( !id[v] ) dfs(v);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("vo21decor.inp", "r") ){
        freopen("vo21decor.inp", "r", stdin);
        freopen("vo21decor.out", "w", stdout);
    }

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++){
        char x; cin >> x;
        if ( x == '1' ) a[i] = 1;
        else a[i] = 0;
    }

    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v), g[v].pb(u);
    }

    for (int i = 1; i <= n; i ++)
        if ( !id[i] ) nn ++, dfs(i);

    pi ans;
    ans = {0, 0};

    int l = 1, sum = 0;

    for (int i = 1; i <= n; i ++){
        sum -= ( s[id[i]] >= 0 ? s[id[i]] : 0 );
        s[id[i]] ++;
        sum += ( s[id[i]] >= 0 ? s[id[i]] : 0 );

        while ( l < i && sum > k ){
            sum -= ( s[id[l]] >= 0 ? s[id[l]] : 0 );
            s[id[l]] --;
            sum += ( s[id[l]] >= 0 ? s[id[l]] : 0 );
            l ++;
        }

        if ( sum <= k && ans.se < i - l + 1 ) ans = {l, i-l+1};
    }

    if ( ans.se == 0 ) cout << -1;
    else cout << ans.fi << ' ' << ans.fi + ans.se - 1;

    return 0;
}
