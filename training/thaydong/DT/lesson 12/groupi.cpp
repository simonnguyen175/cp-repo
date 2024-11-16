#include<bits/stdc++.h>
#define int long long
#define BIT(x,k) ((x>>k)&1)
using namespace std;

int n, m, mx;
int g[52], init[52];

void findClique(int c, int u){
    int szc = __builtin_popcountll(c);

    if ( u == 0 ){
        if ( szc > __builtin_popcountll(mx) ) mx = c;
        return;
    }

    while ( u ){
        int szu = __builtin_popcountll(u);
        if ( szc + szu <= mx ) return;
        int v = __builtin_ctzll(u);
        u ^= (1<<v);
        findClique(c|(1<<v), u&g[v]);
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i ++){
        cin >> u >> v;
        u --, v --;
        g[u] |= (1ll<<v);
        g[v] |= (1ll<<u);
    }

    findClique(0, (1ll<<n)-1);
    for (int i = 0; i < n; i ++) if ( BIT(mx, i) )
        init[i] = 1;
    int lef = mx, rig = ((1ll<<n)-1)^lef;
    mx = 0, findClique(0, rig);
    while ( mx < __builtin_popcount(lef) ){
        int v = __builtin_ctzll(lef);
        lef ^= (1ll<<v), rig |= (1ll<<v);
        mx = 0, findClique(0, rig);
    }

    // TH bang nhau
    if ( __builtin_popcount(lef) == __builtin_popcount(mx) ){
        cout << __builtin_popcount(lef) << '\n';
        for (int i = 0; i < n; i ++) if ( BIT(lef, i) )
            cout << i + 1 << ' ';
        return 0;
    }

    // TH h-1, h va ton tai 1 thang init ma ko thuoc clique ben phai
    for (int i = 0; i < n; i ++)
    if ( BIT(rig, i) && !BIT(mx, i) && init[i] ){
        lef |= (1ll<<i), rig ^= (1ll<<i);
        cout << __builtin_popcount(lef) << '\n';
        for (int j = 0; j < n; j ++) if ( BIT(lef, j) )
            cout << j + 1 << ' ';
        return 0;
    }

    // TH h-1, h va ton tai tat cac thang init thuoc clique ben phai
    while ( mx > __builtin_popcount(lef) ){
        for (int i = 0; i < n; i ++) if ( BIT(mx, i) && !init[i] ){
            rig ^= (1ll<<i), lef |= (1ll<<i);
            break;
        }
        mx = 0, findClique(0, rig);
    }
    cout << __builtin_popcount(lef) << '\n';
    for (int i = 0; i < n; i ++) if ( BIT(lef, i) )
        cout << i + 1 << ' ';
    return 0;

    return 0;
}
