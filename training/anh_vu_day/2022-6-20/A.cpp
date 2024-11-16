#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int n, k, nn;
int g[N], vis[N], a[N], b[N], d[2*N];
bitset<N> f;

void dfs(int u){
    a[nn] ++;
    vis[u] = 1;
    if ( !vis[g[u]] ) dfs(g[u]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    for (int i = 1, x; i <= n; i ++)
        cin >> x, g[i] = x;

    for (int i = 1; i <= n; i ++) if ( !vis[i] )
        nn ++, dfs(i);

    int cur = k, mx = 0, mn, cnt = 0;

//  tim max
    for (int i = 1; i <= nn; i ++) if ( !(a[i]%2) ){
        mx += min(a[i], cur*2);
        cur -= min(a[i]/2, cur);
    }
    for (int i = 1; i <= nn; i ++) if ( a[i]%2 ){
        mx += min(a[i]-1, cur*2);
        cur -= min(a[i]/2, cur);
        cnt ++;
    }
    mx += min(cur, cnt);

//  tim min
    cnt = 0;
    for (int i = 1; i <= nn; i ++) d[a[i]] ++;

    for (int i = 1; i <= n; i ++) if ( d[i] && i * 2 <= n ) {
        if ( d[i] % 2 == 0 ) d[i*2] += (d[i]-1)/2, d[i] = 2;
        else d[i*2] += d[i]/2, d[i] = 1;
    }

    for (int i = 1; i <= n; i ++) if ( d[i] ) b[++cnt] = i;

    f[0] = 1;
    for (int i = 1; i <= cnt; i ++)
        for (int j = 1; j <= d[b[i]]; j ++)
            f |= ( f << b[i] );

    mn = k + !f[k];

    cout << mn << ' ' << mx;

    return 0;
}
