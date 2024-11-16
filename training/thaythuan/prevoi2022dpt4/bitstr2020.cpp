#include<bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e2 + 5;
const ll oo = 1e18;

int n, q;
ll p;
ll f[N][1<<16];
vector<pi> que[N];

void calc(int id, int msk){
    if ( id == n ) { f[id][msk] = 1; return; }
    if ( f[id][msk] != -1 ) return;

    ll res = 0;
    for (int i = 0; i <= 1; i ++){
        int nmsk = msk >> 1;
        if ( i ) nmsk |= (1<<15);

        bool ok = 1;
        for (auto it : que[id+1]){
            int l = it.fi, r = id+1, c = it.se;
            int tmp = nmsk >> ( 16 - (r-l+1) );
            ok &= ( __builtin_popcount(tmp) == c );
        }

        if ( ok ){
            calc(id+1, nmsk);
            res = min(oo, res + f[id+1][nmsk]);
        }
    }

    f[id][msk] = res;
}

void solve(){
    cin >> n >> q >> p;
    for (int i = 1; i <= n; i ++) que[i].clear();
    for (int i = 1; i <= q; i ++){
        int l, r, c;
        cin >> l >> r >> c;
        que[r].pb({l, c});
    }

    for (int i = 0; i <= n; i ++)
    for (int j = 0; j < (1<<16); j ++)
        f[i][j] = -1;

    calc(0, 0);

    int id = 0, cur = 0;
    while ( id < n ){
        cur = cur >> 1;
        if ( f[id+1][cur] >= p )
            cout << 0;
        else{
            if ( f[id+1][cur] != -1 ) p -= f[id+1][cur];
            cur |= (1<<15);
            cout << 1;
        }
        id ++;
    }

    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
