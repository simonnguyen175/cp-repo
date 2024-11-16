#include<bits/stdc++.h>
#define BIT(x,k) ((x>>k)&1)
using namespace std;
const int N = 2e5 + 5;

int n, q;
int d[N][31];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> q;
    for (int i = 1, x; i <= n; i ++)
        cin >> x, d[i][0] = x;

    for (int j = 1; j <= 30; j ++)
    for (int i = 1; i <= n; i ++)
        d[i][j] = d[d[i][j-1]][j-1];

    int u, k;
    while ( q -- ){
        cin >> u >> k;
        for (int i = 0; i <= 30; i ++)
            if ( BIT(k, i) )
                u = d[u][i];
        cout << u << '\n';
    }

    return 0;
}
