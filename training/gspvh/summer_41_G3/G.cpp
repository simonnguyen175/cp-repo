#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 3e5 + 5;

int n, m;
int deg[N], a[N], p[N];
vector<int> g[N];
struct edg{
    int u, v;
} edges[N];
queue<int> q;

bool check(int mid){
    for (int i = 1; i <= n; i ++)
        g[i].clear(), deg[i] = 0;

    for (int i = 1; i <= mid; i ++)
        g[edges[i].u].pb(edges[i].v), deg[edges[i].v] ++;

    while ( q.size() ) q.pop();
    for (int i = 1; i <= n; i ++)
        if ( !deg[i] ) q.push(i);

    int cnt = 0;
    while ( q.size() ){
        if ( q.size() > 1 ) return false;
        a[++cnt] = q.front();
        q.pop();
        for (int v : g[a[cnt]]){
            deg[v] --;
            if ( deg[v] == 0 ) q.push(v);
        }
    }

    for (int i = 1; i <= n; i ++)
        p[i] = a[i];

    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("harem.inp", "r") ){
        freopen("harem.inp", "r", stdin);
        freopen("harem.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
        cin >> edges[i].u >> edges[i].v;

    int lo = 1, hi = m, res = -1;
    while ( lo <= hi ){
        int mid = ( lo + hi ) / 2;
        if ( check(mid) ) res = mid, hi = mid - 1;
        else lo = mid + 1;
    }

    cout << res << '\n';
    if ( res != -1 )
        for (int i = 1; i <= n; i ++)
            cout << p[i] << ' ';

    return 0;
}
