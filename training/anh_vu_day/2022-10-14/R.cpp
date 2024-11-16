#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, q;
int nxt[N], Par[N], Rank[N];

int Find(int u){
    if ( u == Par[u] ) return u;
    else return Par[u] = Find(Par[u]);
}

void Join(int u, int v){
    u = Find(u), v = Find(v);
    if ( u != v ){
        if ( Rank[u] < Rank[v] ) swap(u, v);
        if ( Rank[u] == Rank[v] ) Rank[u] ++;
        Par[v] = u;
    }
}

int findNxt(int u){
    if ( u == nxt[u] ) return u;
    else return nxt[u] = findNxt(nxt[u]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i ++) nxt[i] = i, Par[i] = i, Rank[i] = 0;

    for (int i = 1; i <= q; i ++){
        int type, x, y;
        cin >> type >> x >> y;
        if ( type == 1 ) Join(x, y);
        else if ( type == 2 ){
            for (int i = x; i < y; i = findNxt(i)){
                Join(i, i + 1);
                nxt[i] = i + 1;
            }
        }
        else{
            if ( Find(x) == Find(y) ) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
