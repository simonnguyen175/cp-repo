#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 3e5 + 5;
const ll oo = 1e15;

int n, k;
int a[N], cles[N];
ll s[N];
vector<int> cost[N];

ll get(int cwin){
    if ( cwin >= 2 && cles[cwin-2] >= k ) return s[cwin];
    if ( cles[cwin] < k ) return oo;

    int rem = k - ( cwin >= 2 ? cles[cwin-2] : 0 );
    if ( cwin < rem ) return oo;

    ll res = 0;
    vector<int> cont;
    priority_queue<int> heap;
    for (int i = cwin-1; i <= cwin; i ++)
    for (auto x : cost[i]){
        res += x;
        heap.push(x);
        while ( heap.size() > rem ){
            cont.pb(heap.top());
            res -= heap.top();
            heap.pop();
        }
    }

    for (int i = 0; i <= n+1; i ++) if ( i != cwin-1 && i != cwin )
    for (auto x : cost[i]) cont.pb(x);

    sort(cont.begin(), cont.end());
    for (int i = 0; i < cwin-rem; i ++) res += cont[i];

    return res;
}

void solve(){
    cin >> n >> k;
    k = n + 1 - k;

    for (int i = 0; i <= n+1; i ++) cost[i].clear();
    for (int i = 1, p, e; i <= n; i ++){
        cin >> p >> e;
        p = min(p, n+1);
        cost[p].pb(e);
        a[i] = e;
    }

    if ( k == 0 ) { cout << 0 << '\n'; return; }

    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i ++) s[i] = s[i-1] + a[i];
    for (int i = 1; i <= n+1; i ++) sort(cost[i].begin(), cost[i].end());
    cles[0] = cost[0].size();
    for (int i = 1; i <= n+1; i ++) cles[i] = cles[i-1] + cost[i].size();

    ll res = oo;
    for (int i = 1; i <= n; i ++)
        res = min(res, get(i));

    if ( res == oo ) cout << -1 << '\n';
    else cout << res << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("H.inp", "r") ){
        freopen("H.inp", "r", stdin);
        freopen("H.out", "w", stdout);
    }

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
