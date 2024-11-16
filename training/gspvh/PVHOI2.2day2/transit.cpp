#include<bits/stdc++.h>
#define BIT(x, k) ((x>>k)&1)
#define ll long long
#define pi pair<ll, int>
#define fi first
#define se second
using namespace std;
const int N = 1505;
const ll oo = 1e15;

int n, m, q;
int f[N];
ll w[N][N], d[N][N];
priority_queue<pi, vector<pi>, greater<pi>> heap;
bool ck1 = 1;

void dijkstra(int x){
    d[x][x] = 0;
    heap.push({0, x});
    while ( heap.size() ){
        int u = heap.top().se;
        ll du = heap.top().fi;
        heap.pop();
        if ( du != d[x][u] ) heap.pop();
        for (int v = 1; v <= n; v ++){
            if ( d[x][v] > d[x][u] + w[u][v] ){
                d[x][v] = d[x][u] + w[u][v];
                heap.push({d[x][v], v});
            }
        }
    }
}

namespace sub4{
    ll dd[N][1<<6][6];

    void anal(int x){
        for (int i = 0; i < (1<<m); i ++)
        for (int j = 0; j <= m; j ++)
            dd[x][i][j] = oo;

        for (int i = 1; i <= m; i ++)
            dd[x][1<<(i-1)][i] = d[x][f[i]];

        for (int t = 0; t < (1<<m); t ++)
        for (int i = 1; i <= m; i ++){
            for (int j = 1; j <= m; j ++){
                if ( !BIT(t, j-1) )
                    dd[x][t|(1<<(j-1))][j] = min(dd[x][t|(1<<(j-1))][j], dd[x][t][i] + d[f[i]][f[j]]);
            }
        }
    }

    void solve(){
        for (int i = 1; i <= n; i ++)
            anal(i);

        while ( q -- ){
            int u, v;
            ll res = oo;
            cin >> u >> v;
            for (int i = 1; i <= m; i ++)
                if ( res > dd[u][(1<<m)-1][i] + d[f[i]][v] )
                    res = dd[u][(1<<m)-1][i] + d[f[i]][v];
            cout << res << ' ';
        }
    }
}

namespace sub1{
	void solve(){
        while ( q -- ){
            int u, v; cin >> u >> v;
            if ( u == v ) { cout << m + 1 << ' '; continue; }
			int res = m + 2;
			for (int i = 1; i <= m; i ++){
				if ( f[i] == u ) res --;
				if ( f[i] == v ) res --;
			}
            cout << res << ' ';
		}
	}
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("transit.inp", "r") ){
        freopen("transit.inp", "r", stdin);
        freopen("transit.out", "w", stdout);
    }

    cin >> n >> m >> q;
    for (int i = 1; i <= m; i ++){
        cin >> f[i];
    }

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++){
        cin >> w[i][j];
        ck1 &= ( w[i][j] == 1 );
        d[i][j] = oo;
    }


    for (int i = 1; i <= n; i ++)
        dijkstra(i);

    if ( ck1 ) { sub1::solve(); return 0; }

    if ( m <= 6 ) { sub4::solve(); return 0; }

    return 0;
}
