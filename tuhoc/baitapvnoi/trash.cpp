#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e3 + 5;
const int oo = 1e9;

int n, m, t, k, mne;
vector<pi> adj[N], ad[N];
vector<int> ans;
int d[N], f[N][105];

void dijkstra(){
    priority_queue<pi, vector<pi>, greater<pi>> heap;
    for (int i = 1; i <= n; i ++) d[i] = oo;
    d[t] = 0, heap.push({0, t});

    while ( heap.size() ){
        int u = heap.top().se;
        int du = heap.top().fi;
        heap.pop();

        if ( du != d[u] ) continue;

        for (auto it : adj[u]){
            int v = it.fi, w = it.se;
            if ( d[v] > d[u] + w ){
                d[v] = d[u] + w;
                heap.push({d[v], v});
            }
        }
    }
}

int calc(int u, int len){
    if ( u == t )
        if ( len ) return 0;
        else return 1;

    if ( f[u][len-d[u]] != -1 ) return f[u][len-d[u]];

//    cout << u << ' ' << len << " : \n";
    int res = 0;
    for (auto it : ad[u]){
        int v = it.fi, w = it.se;
        if ( len-w >= d[v] ){
//            cout << "-> " << v << ' ' << len-w << '\n';
            int tmp = calc(v, len-w);
            res = min(k, res + tmp);
        }
    }

//    cout << res << '\n';

    f[u][len-d[u]] = res;

    return res;
}

vector<int> anal(int len){
    vector<int> res;

    if ( f[1][len-d[1]] < k ){
        res.pb(oo);
        return res;
    }

    int u = 1, cur = k;
    res.pb(1);
    while ( len ){
//        cout << u << ' ' << cur << ' ' << len << '\n';
        for (auto it : ad[u]){
            int v = it.fi, w = it.se;

            if ( len - w < d[v] ) continue;

            if ( f[v][len-w-d[v]] >= cur ){
                res.pb(v);
                u = v;
                len -= w;
//                cout << "-> " << v << ' ' << cur << '\n';
                break;
            }
            else{
                cur -= f[v][len-w-d[v]];
//                cout << "skip " << v << ' ' << cur << '\n';
            }
        }
    }

    return res;
}

void update(vector<int> tmp){
    bool ck = 0;

    for (int i = 0; i < min(tmp.size(), ans.size()); i ++)
        if ( ans[i] > tmp[i] ) ck = 1;
        else if ( ans[i] < tmp[i] ) return;

    if ( ck ) ans = tmp;
    else if ( ans.size() > tmp.size() ) ans = tmp;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> m >> t >> k;

    mne = oo;
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[v].pb({u, w});
        ad[u].pb({v, w});
        mne = min(mne, w);
    }

    dijkstra();

//    for (int u = 1; u <= n; u ++)
//        cout << d[u] << ' ';
//    cout << '\n';

    if ( d[1] == oo ){
        cout << -1; return 0;
    }

    memset(f, -1, sizeof f);
    f[t][0] = 1;
    for (int len = d[1]; len <= d[1] + mne; len ++){
        f[1][len-d[1]] = calc(1, len);
//        cout << len << ' ' << f[1][len-d[1]] << '\n';
    }

    for (int u = 1; u <= n; u ++)
        sort(ad[u].begin(), ad[u].end());

    ans.pb(oo);
    for (int len = d[1]; len <= d[1] + mne; len ++)
        update(anal(len));

    if ( ans.size() == 1 ){
        cout << -1;
        return 0;
    }

    cout << ans.size() << '\n';
    for (int u : ans)
        cout << u << ' ';

    return 0;
}
