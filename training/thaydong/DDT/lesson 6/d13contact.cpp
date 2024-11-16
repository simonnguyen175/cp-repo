#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, m;
int D[20][N], Rank[20][N];

int Find(int u, int k){
    if ( D[k][u] == u ) return u;
    else return D[k][u] = Find(D[k][u], k);
}

void Join(int u, int v, int k){
    u = Find(u, k); v = Find(v, k);

    if ( u != v ){
        if ( Rank[k][u] < Rank[k][v] ) swap(u, v);

        D[k][v] = u;

        if ( Rank[k][u] == Rank[k][v] ) Rank[k][u] ++;
    }
}

int main(){
    cin >> n >> m;

    for (int k = 0; k <= 18; k ++)
        for (int i = 1; i <= n; i ++)
            D[k][i] = i;

    memset(Rank, 0, sizeof Rank);

    for (int i = 1; i <= m; i ++){
        int p, q, l;
        cin >> p >> q >> l;
        int off = 0;
        for (int k = 18; k >= 0; k --)
            if ( l >= (1<<k) ){
                Join(p+off, q+off, k);
                l -= (1<<k);
                off += (1<<k);
            }
    }

    for (int k = 18; k >= 1; k --){
        for (int i = 1; i <= n; i ++){
            int r = Find(i, k);
            Join(i, r, k-1);
            Join(i+ (1<<(k-1)), r + (1<<(k-1)), k-1);
        }
    }

    int ans = 1;

    for (int i = 1; i <= n; i ++)
        if ( Find(i, 0) == i ) (ans *= 2) %= MOD;

    cout << ans;

    return 0;
}
