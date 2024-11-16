#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e4 + 5;

int n, k, s, m;
map<string, int> id;
map<pair<int, int>, int> cont;
string per[N];
vector<int> adj[N];
int deg[N];

void Insert(string x){
    id[x] = ++n;
    per[n] = x;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("specone.inp", "r") ){
        freopen("specone.inp", "r", stdin);
        freopen("specone.out", "w", stdout);
    }

    cin >> n >> k >> s >> m;
    n = 0;
    for (int i = 1; i <= s; i ++){
        string spe;
        cin >> spe;
        Insert(spe);
    }

    for (int i = 1; i <= m; i ++){
        string u, v;
        cin >> u >> v;
        if ( !id[u] ) Insert(u);
        if ( !id[v] ) Insert(v);

        if ( id[u] > id[v] ) swap(u, v);
        if ( cont[{id[u], id[v]}] ) continue;

        adj[id[u]].pb(id[v]);
        adj[id[v]].pb(id[u]);

        cont[{id[u], id[v]}] = 1;
    }

    queue<int> q;
    for (int i = 1; i <= n; i ++) deg[i] = k;
    for (int i = 1; i <= s; i ++)
        q.push(i), deg[i] = 0;
    while ( q.size() ){
        int u = q.front();
        q.pop();
        for (int v : adj[u]) if ( deg[v] ){
            deg[v] --;
            if ( !deg[v] ) q.push(v);
        }
    }

    vector<string> ans;
    for (int i = 1; i <= n; i ++)
        if ( !deg[i] ) ans.pb(per[i]);
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (string x : ans) cout << x << ' ';

    return 0;
}
