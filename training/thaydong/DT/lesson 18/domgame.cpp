#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 2e3 + 5;
const int row[] = {0, 0, 1, -1};
const int col[] = {1, -1, 0, 0};

int m, n, t, nn;
vector<int> adj[N*N];
char a[N][N];
int id[N][N], vis[N*N], lef[N*N], rig[N*N];

bool inside(int x, int y){
    return ( x >= 1 && x <= m && y >= 1 && y <= n );
}

bool go(int u){
    if ( vis[u] != t ) vis[u] = t;
    else return 0;

    for (int v : adj[u])
        if ( !lef[v] || go(lef[v]) ){
            lef[v] = u;
            rig[u] = v;
            return 1;
        }

    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> m >> n;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
        cin >> a[i][j];

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++) if ( a[i][j] != '#' )
        id[i][j] = ++nn;

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++) if ( a[i][j] != '#' && (i + j) % 2 == 0 ){
        for (int k = 0; k < 4; k ++){
            int ni = i + row[k], nj = j + col[k];
            if ( inside(ni, nj) && a[ni][nj] != '#' )
                adj[id[i][j]].pb(id[ni][nj]);
                adj[id[ni][nj]].pb(id[i][j]);
        }
    }

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++) if ( a[i][j] != '#' && (i + j) % 2 == 0 ){
        t ++;
//        cout << i << ' ' << j << ' ' << id[i][j] << '\n';
        bool tmp = go(id[i][j]);
//        cout << " -> " << tmp << '\n';
    }

    ll ans = nn/2 * (nn/2 - 1);

//    for (int i = 1; i <= nn; i ++)
//        cout << lef[i] << ' ';
//    cout << '\n';

    for (int i = 1; i <= nn; i ++) if ( !lef[i] ){
        for (int j = 1; j <= nn; j ++) vis[j] = 0;
//        cout << i << " : \n";
        queue<int> q;
        vis[i] = 1;
        q.push(i);

        int cnt = 0;

        while ( q.size() ){
            int u = q.front();
            if ( lef[u] ) cnt ++;
            q.pop();

            if ( rig[u] ) { vis[rig[u]] = 1; q.push(rig[u]); continue; }

            for (int v : adj[u]) if ( !vis[v] )
                vis[v] = 1, q.push(v);
        }

        ans += nn/2 - cnt;
    }

    cout << min(ans, (ll)1e6);

    return 0;
}
