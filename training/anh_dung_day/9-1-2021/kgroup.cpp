#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 8e3 + 5;
const int base1 = 1e9 + 7;
const int base2 = 1e9 + 9;
const ll MOD = 2020202111;
const ll oo = 1e18;

int n, k;
int edges[N], d[N], c[N][N];
bool vis[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        for (int j = i + 1; j <= n; j ++){
            int u = i, v = j, w;
            w = (1LL * base1 * u % MOD + 1LL * base2 * v % MOD) % MOD;
            c[u][v] = c[v][u] = w;
        }

    d[1] = 0;
    for (int i = 2; i <= n; i ++) d[i] = c[1][i];
    memset(vis, 0, sizeof vis);
    vis[1] = 1;

    for (int j = 2; j <= n; j ++){
        int u; int w = INT_MAX;

        for (int i = 1; i <= n; i ++)
            if ( !vis[i] && d[i] < w )
                u = i, w = d[i];

        vis[u] = 1; edges[j-1] = w;

        for (int i = 1; i <= n; i ++)
            if ( !vis[i] )
                d[i] = min(d[i], c[u][i]);
    }


    sort(edges + 1, edges + n, greater<ll>());

    cout << edges[k-1];

    return 0;
}
