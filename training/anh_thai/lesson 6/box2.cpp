#include<bits/stdc++.h>
#define pi pair<int, int>
#define pii pair<pi, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n;
pii a[N];
vector<int> cont, ans[N];
map<int, int> id;
int f[N], bit[N];

void update(int u, int v){
    for (; u >= 1; u -= u&(-u)) bit[u] = max(bit[u], v);
}

int get(int u){
    int res = 0;
    for (; u <= n; u += u&(-u)) res = max(res, bit[u]);
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("box2.inp", "r") ){
        freopen("box2.inp", "r", stdin);
        freopen("box2.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].fi.fi >> a[i].fi.se;
        cont.pb(a[i].fi.se);
        a[i].fi.se *= -1;
        a[i].se = i;
    }

    sort(a+1, a+1+n);
    sort(cont.begin(), cont.end());
    for (int i = 0; i < cont.size(); i ++) id[cont[i]] = i + 1;

    for (int i = 1; i <= n; i ++) a[i].fi.se *= -1;

    set<int> s;
    for (int i = 1; i <= n; i ++){
        f[i] = get(id[a[i].fi.se]) + 1;
        update(id[a[i].fi.se], f[i]);
        ans[f[i]].pb(a[i].se);
        s.insert(f[i]);
    }

    cout << s.size() << '\n';
    for (int x : s){
        reverse(ans[x].begin(), ans[x].end());
        cout << ans[x].size() << ' ';
        for (int id : ans[x]) cout << id << ' ';
        cout << '\n';
    }

    return 0;
}
