#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 2e5 + 5;

int n, k;
int a[N];
vector<int> pos[N];
vector<pair<int, int>> last;
bool vis[N];
int st[4*N];

void update(int id, int l, int r, int u, int v){
    if ( l > u || r < u ) return;

    if ( l == r && l == u ){
        st[id] = v;
        return;
    }

    int mid = ( l + r ) / 2;

    update(id*2, l, mid, u, v);
    update(id*2+1, mid + 1, r, u, v);

    st[id] = min(st[id*2], st[id*2+1]);
}

int get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return INT_MAX;

    if ( u <= l && r <= v ) return st[id];

    int mid = ( l + r ) / 2;

    return min(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

int main(){
    freopen("subpermu.inp", "r", stdin);
    freopen("subpermu.out", "w", stdout);

    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        pos[a[i]].pb(i);
        update(1, 1, n, i, a[i]);
    }

    for (int i = 1; i <= k; i ++)
        last.pb({pos[i][pos[i].size()-1], i});

    sort(last.begin(), last.end());

    vector<int> ans;
    memset(vis, 0, sizeof vis);

    int l = 1;
    for (auto it : last){
        int r = it.first, a = it.second;
        if ( vis[a] ) continue;
        int b = get(1, 1, n, l, r);

        while ( b < a ){
            ans.pb(b);
            vis[b] = 1;
            for (int id : pos[b])
                update(1, 1, n, id, INT_MAX);
            l = pos[b][0] + 1;
            b = get(1, 1, n, l, r);
        }
        for (int id : pos[a])
            update(1, 1, n, id, INT_MAX);
        vis[a] = 1;
        l = r;
        ans.pb(a);
    }

    for (auto x : ans) cout << x << ' ';

    return 0;
}
