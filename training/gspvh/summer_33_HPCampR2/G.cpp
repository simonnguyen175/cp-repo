#include<bits/stdc++.h>
#define simon "raspored"
#define pb push_back
#define ll long long
using namespace std;
const int N = 3e5 + 5;

int sub, n, Q;
struct que{
    int p, t, d;
} q[N];
int t[N], d[N], bit[2*N];
ll bi[2*N];
vector<int> comp;
ll ans = 0;

void update(int u, int v){
    for (; u >= 1; u -= u&-u)
        bit[u] += v;
}

int get(int u){
    int res = 0;
    for (; u <= comp.size(); u += u&-u){
        res += bit[u];
//        cerr << u << ' ' << bit[u] << '\n';
    }
    return res;
}

void up(int u, int v){
    for (; u <= comp.size(); u += u&-u)
        bi[u] += v;
}

ll ge(int u){
    ll res = 0;
    for (; u >= 1; u -= u&-u)
        res += bi[u];
    return res;
}

int id(int x){
    return upper_bound(comp.begin(), comp.end(), x) - comp.begin();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> sub >> n >> Q;
    for (int i = 1; i <= n; i ++){
        cin >> t[i] >> d[i];
        ans += t[i];
        comp.pb(d[i]);
    }
    sort(comp.begin(), comp.end());
    ll s = 0;
    for (int i = 0; i < n; i ++)
        s += comp[i], ans -= s;

    for (int i = 1; i <= Q; i ++){
        cin >> q[i].p >> q[i].t >> q[i].d;
        comp.pb(q[i].d);
    }
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    for (int i = 1; i <= n; i ++)
        update(id(d[i]), 1), up(id(d[i]), d[i]);

    cout << ans << '\n';
    for (int i = 1; i <= Q; i ++){
        int pos = q[i].p;

//        cout << pos << ' ' << t[pos] << ' ' << d[pos] << ' ' << get(id(d[pos])) << '\n';

        ans -= t[pos];
        ans += 1LL * d[pos] * get(id(d[pos])) + ge(id(d[pos])-1);
        update(id(d[pos]), -1);
        up(id(d[pos]), -d[pos]);

        t[pos] = q[i].t;
        d[pos] = q[i].d;

        update(id(d[pos]), 1);
//        cout << " -> " << t[pos] << ' ' << d[pos] << ' ' << get(id(d[pos])) << '\n';
        ans += t[pos];
        ans -= 1LL * d[pos] * get(id(d[pos])) + ge(id(d[pos])-1);
        up(id(d[pos]), d[pos]);

        cout << ans << '\n';
    }

    return 0;
}
