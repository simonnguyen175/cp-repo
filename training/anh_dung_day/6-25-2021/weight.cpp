#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, m;
int Par[N], Rank[N];
long long d[N];

int findRoot(int u){
    if ( Par[u] == u ) return u;
    else{
        int curP = Par[u];
        Par[u] = findRoot(Par[u]);
        d[u] += d[curP];
        return Par[u];
    }
}

void Join(int u, int v, int w){
    int ru = findRoot(u), rv = findRoot(v);
    if ( ru != rv ){
        if ( Rank[ru] < Rank[rv] ){
            swap(ru, rv); swap(u, v); w *= -1;
        }
        d[rv] = d[u] + w - d[v];
        Par[rv] = ru;
        if ( Rank[ru] == Rank[rv] ) Rank[ru] ++;
    }
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    while (cin >> n >> m){
        if ( n == 0 && m == 0 ) return 0;
        for (int i = 1; i <= n; i ++){
            Par[i] = i;
            Rank[i] = 0;
            d[i] = 0;
        }

        for (int i = 1; i <= m; i ++){
            char type;
            int a, b, c;
            cin >> type;
            if ( type == '!' ){
                cin >> a >> b >> c;
                Join(a, b, c);
            }
            else{
                cin >> a >> b;
                if ( findRoot(a) != findRoot(b) ) cout << "UNKNOWN" << '\n';
                else{
                    cout << d[b] - d[a] << '\n';
                }
            }
        }
    }

    return 0;
}
