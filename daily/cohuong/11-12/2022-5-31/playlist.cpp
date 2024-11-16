#include<bits/stdc++.h>
#define BIT(x,k) ((x>>k)&1)
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int MOD = 1e9 + 7;

int n, T;
pi a[16];
int c[1<<15], f[1<<15][16];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    return a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> T;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].fi >> a[i].se;

    for (int i = 1; i < (1<<n); i ++)
    for (int j = 1; j <= n; j ++) if ( BIT(i, j-1) )
        c[i] += a[j].fi;

    f[0][0] = 1;
    int ans = 0;
    for (int t = 0; t < (1<<n); t ++)
    for (int i = 0; i <= n; i ++) if ( f[t][i] ){
        if ( c[t] == T ) ans = add(ans, f[t][i]);
        for (int j = 1; j <= n; j ++) if ( !BIT(t, j-1) && a[j].se != a[i].se )
            f[t|(1<<(j-1))][j] = add(f[t|(1<<(j-1))][j], f[t][i]);
    }

    cout << ans;

    return 0;
}
