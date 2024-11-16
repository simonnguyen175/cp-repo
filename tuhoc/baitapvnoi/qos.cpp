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
        if ( f[u][len] != -1 ) return f[u][len];
        else return 0;

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
    memset(f, -1, sizeof f);

    mne = oo;
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        if ( u == v && u == t ) f[t][w] = 1;
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

    f[t][0] = 1;
    int sum = 0;
    for (int len = d[1]; len <= d[1] + mne; len ++){
        f[1][len-d[1]] = calc(1, len);
        sum = min(k, sum + f[1][len-d[1]]);
//        cout << len << ' ' << f[1][len-d[1]] << '\n';
    }

    if ( sum < k ){
        cout << -1; return 0;
    }

    for (int u = 1; u <= n; u ++)
        sort(ad[u].begin(), ad[u].end());

    int u = 1, du = d[1];
    int tt = 0;
    ans.pb(1);
    int cntt = 0;

    while ( true ){
//        if ( tt ++ == 10 ) break;
        if ( !k ) break;

//        cout << u << ' ' << du << ' ' << k << '\n';

        for (auto it : ad[u]){
            int v = it.fi, w = it.se;
            int cnt = 0;

            if ( du - w + mne >= d[v] )
            for (int len = d[v]; len <= du-w+mne; len ++) if ( f[v][len-d[v]] != -1 ){
//                cout << v << ' ' << len << ' ' << f[v][len-d[v]] << '\n';
                cnt = min(k, cnt + f[v][len-d[v]]);
            }

//            cout << "-> " << v << ' ' << cnt << ' ';
            if ( cnt >= k ){
                ans.pb(v);
                u = v;
                du -= w;
                if ( u == t ) k --;
//                cout << "pick \n";
                break;
            }
            else{
                k -= cnt;
//                cout << "skip\n";
            }
        }
    }

    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';

    return 0;
}
