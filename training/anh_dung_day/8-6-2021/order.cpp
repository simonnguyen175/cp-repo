#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n, m;
int sk[2*N], a[2*N], degin[N], tmp[N], ans[N];
vector<int> adj[N];

void init(){
    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int k; cin >> k;
        for (int j = 1; j <= k; j ++)
            cin >> a[sk[i-1]+j];
        sk[i] = sk[i-1] + k;
    }
}

bool check(int x){
    for (int i = 1; i <= n; i ++) adj[i].clear();

    memset(degin, 0, sizeof degin);

    for (int i = 1; i <= x; i ++)
        for (int j = sk[i-1] + 1; j < sk[i]; j ++){
            adj[a[j]].pb(a[j+1]);
            degin[a[j+1]] ++;
        }

    priority_queue<int, vector<int>, greater<int>> heap;

    for (int u = 1; u <= n; u ++) if ( degin[u] == 0 ) heap.push(u);

    int cnt = 0;
    while ( heap.size() ){
        int u = heap.top();
        heap.pop();
        tmp[++cnt] = u;

        for (int v : adj[u]){
            degin[v] --;
            if ( degin[v] == 0 ) heap.push(v);
        }
    }

    if ( cnt < n ) return false;
    else{
        for (int i = 1; i <= n; i ++) ans[i] = tmp[i];
        return true;
    }
}

void solve(){
    int lo = 1, hi = m, res;
    while ( lo <= hi ){
        int mid = ( lo + hi ) / 2;
        if ( check(mid) ){
            res = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }

    for (int i = 1; i <= n; i ++) cout << ans[i] << ' ';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("order.inp", "r") ){
        freopen("order.inp", "r", stdin);
        freopen("order.out", "w", stdout);
    }

    init();
    solve();
    return 0;
}
