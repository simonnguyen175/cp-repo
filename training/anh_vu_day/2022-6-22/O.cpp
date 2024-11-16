#include<bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 5;

int n, q;
pi h[N], y[N];
int Par[N], Size[N];
ll ans[N];
map<int, int> d;
ll cur = 0;

int Find(int u){
    if ( u == Par[u] ) return u;
    else return Par[u] = Find(Par[u]);
}

void Join(int u, int v){
    u = Find(u), v = Find(v);
    if ( u != v ){
        cur += 1LL * Size[u] * Size[v];
        if ( Size[v] > Size[u] ) swap(u, v);
        Par[v] = u;
        Size[u] += Size[v];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i ++)
        cin >> h[i].fi, h[i].se = i;
    for (int i = 1; i <= q; i ++)
        cin >> y[i].fi, y[i].se = i;
    sort(h+1, h+1+n);
    sort(y+1, y+1+q);

    for (int i = 1; i <= n; i ++) Par[i] = i, Size[i] = 1;

    int id = 1;
    for (int i = 1; i <= q; i ++){
        while ( id <= n && h[id].fi <= y[i].fi ){
            cur ++;
            if ( d[h[id].se-1] ) Join(h[id].se, h[id].se-1);
            if ( d[h[id].se+1] ) Join(h[id].se, h[id].se+1);
            d[h[id].se] = 1;
            id ++;
        }
        ans[y[i].se] = cur;
    }

    for (int i = 1; i <= q; i ++)
        cout << ans[i] << '\n';

    return 0;
}
