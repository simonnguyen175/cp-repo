#include<bits/stdc++.h>
#define BIT(x,k) ((x>>k)&1)
using namespace std;
const int N = 21;
const int oo = 1e9;

int n, m;
string s;
int c[N][1<<N], w[1<<N], f[1<<N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    cin >> s;
    for (int i = 1; i < n; i ++){
        int u = s[i]-'a', v = s[i-1]-'a';
        c[u][1<<v] ++;
        c[v][1<<u] ++;
    }

    for (int i = 0; i < m; i ++)
    for (int t = 1; t < (1<<m); t ++)
    for (int j = 0; j < m; j ++) if ( BIT(t, j) ){
        c[i][t] = c[i][t^(1<<j)] + c[i][1<<j];
        break;
    }

    for (int t = 1; t < (1<<m); t ++){
        int k = ((1<<m)-1) ^ t;
        for (int i = 0; i < m; i ++) if ( BIT(t, i) )
            w[t] += c[i][k];
    }

    for (int t = 1; t < (1<<m); t ++)
        f[t] = oo;
    for (int t = 1; t < (1<<m); t ++)
    for (int i = 0; i < m; i ++) if ( BIT(t, i) )
        f[t] = min(f[t], f[t^(1<<i)] + w[t]);

    cout << f[(1<<m)-1];

    return 0;
}
