#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e6 + 5;

int F, M, ne = 0;
int sz[N], ver[N], s[N], deg[N], del[N], w[N], cur[N];
vector<int> f[N], lab[N];
pi edg[N];
map<pi, int> id;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("pgraph.inp", "r") ){
        freopen("pgraph.inp", "r", stdin);
        freopen("pgraph.out", "w", stdout);
    }

    cin >> F >> M;
    for (int i = 1; i <= F; i ++){
        cin >> sz[i];
        for (int j = 1, u; j <= sz[i]; j ++)
            cin >> ver[j];
        ver[sz[i]+1] = ver[1];

        for (int j = 2; j <= sz[i] + 1; j ++){
            int u = ver[j], v = ver[j-1];
            if ( u > v ) swap(u, v);
            if ( !id[{u, v}] ) id[{u, v}] = ++ne, edg[ne] = {u, v};
            deg[id[{u, v}]] ++;
            lab[id[{u, v}]].pb(i);
            f[i].pb(id[{u, v}]);
        }

        cin >> s[i];
    }

    queue<int> q;
    vector<int> ord;
    for (auto it : id) if ( deg[it.se] <= 1 )
        q.push(it.se);

    while ( q.size() ){
        int ce = q.front();
        ord.pb(ce);
        q.pop();

        for (int x : lab[ce]) if ( !del[x] ){
            del[x] = 1;
            for (int y : f[x]) if ( deg[y] > 1 ){
                deg[y] --;
                q.push(y);
            }
        }
    }

    reverse(ord.begin(), ord.end());
    for (int e : ord){
        for (int x : lab[e]) if ( sz[x] == 1 )
            w[e] = ( s[x] - cur[x] + M ) % M;
        for (int x : lab[e]){
            sz[x] --;
            ( cur[x] += w[e] ) %= M;
        }
    }

    for (auto it : id)
        cout << it.fi.fi << ' ' << it.fi.se << ' ' << w[it.se] << '\n';

    return 0;
}
