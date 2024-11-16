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
        c |= (1<<v);
        u &= g[v];
        findClique(c, u);
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i ++){
        cin >> u >> v;
        u --, v --;
        g[u] |= (1<<v);
        g[v] |= (1<<v);
    }

    findClique(0, (1<<n)-1);
    for (int i = 0; i < n; i ++) if ( BIT(mx, i) )
        init[i] = 1;
    int lef = mx, rig = ((1<<n)-1)^lef;
    findClique(0, rig);
    while ( mx < __builtin_popcount(lef) ){
        int v = __builtin_ctzll(lef);
        lef ^= (1<<v);
        rig |= (1<<v);
        findClique(0, rig);
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
        lef |= (1<<i);
        rig ^= (1<<i);
        cout << __builtin_popcount(lef) << '\n';
        for (int j = 0; j < n; j ++) if ( BIT(lef, j) )
            cout << j + 1 << ' ';
        return 0;
    }

    // TH h-1, h va ton tai tat cac thang init thuoc clique ben phai
    while ( mx > __builtin_popcount(lef) ){
        for (int i = 0; i < n; i ++) if ( BIT(mx, i) && !init[i] ){
            rig ^= (1<<i);
            lef |= (1<<i);
            break;
        }
        findClique(0, rig);
    }
    cout << __builtin_popcount(lef) << '\n';
    for (int j = 0; j < n; j ++) if ( BIT(lef, j) )
        cout << j + 1 << ' ';

    return 0;
}
