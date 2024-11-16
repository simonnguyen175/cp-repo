#include<bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const int M = 1e7 + 5;

int n;
vector<int> p;
vector<pair<int, int>> edges[M];
int nxt[M], id[M], Par[N], Rank[N];

int Find(int u){
    if ( u == Par[u] ) return u;
    else return Par[u] = Find(Par[u]);
}

bool Join(int u, int v){
    u = Find(u), v = Find(v);
    if ( u != v ){
        if ( Rank[u] < Rank[v] ) swap(u, v);
        Par[v] = u;
        if ( Rank[u] == Rank[v] ) Rank[u] ++;
        return true;
    }
    else return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++){
        int x; cin >> x;
        p.pb(x);
    }

    sort(p.begin(),p.end());
    p.erase(unique(p.begin(), p.end()), p.end());

    for (int i = 0; i < p.size(); i ++)
        nxt[p[i]] = p[i], id[p[i]] = i + 1;

    for (int i = M-2; i >= 1; i --)
        if ( !nxt[i] ) nxt[i] = nxt[i+1];

    for (int i = 0; i < p.size(); i ++){
        if ( nxt[p[i]+1] ){
            if ( 2 * p[i] >= M || nxt[2*p[i]] != nxt[p[i]+1] )
                edges[nxt[p[i]+1]-p[i]].pb({i + 1, id[nxt[p[i]+1]]});
        }

        for (int j = 2 * p[i]; j < M && nxt[j]; j += p[i])
            if ( j + p[i] >= M || nxt[j+p[i]] != nxt[j] )
                edges[nxt[j]-j].pb({i + 1, id[nxt[j]]});
    }

    for (int i = 1; i <= n; i ++) Par[i] = i, Rank[i] = 0;

    ll ans = 0;

    for (int i = 0; i < M; i ++)
        for (auto it : edges[i]){
            //cout << it.fi << ' ' << it.se << '\n';
            if ( Join(it.fi, it.se) )
                ans += i;
        }

    cout << ans;

    return 0;
}
