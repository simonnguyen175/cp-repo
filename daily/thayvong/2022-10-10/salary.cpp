#include<bits/stdc++.h>
#define BIT(x, k) ((x>>k)&1)
using namespace std;
const int N = 2e6;

int n, m;
int a[N], b[N], s[N], sum[N], f[N];

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], s[i] = s[i-1] + a[i];
    for (int i = 1; i <= m; i ++)
        cin >> b[i];

    for (int i = 0; i < (1<<m); i ++){
        sum[i] = 0;
        for (int j = 1; j <= m; j ++) if ( BIT(i, j-1) )
            sum[i] += b[j];
    }

    memset(f, -1, sizeof f);

    f[0] = 0;
    for (int i = 0; i < (1<<m); i ++) if ( f[i] != -1 ){
        if ( f[i] == n )  { cout << "Yes\n"; return; }

        int rem = sum[i] - s[f[i]];

        for (int j = 1; j <= m; j ++) if ( !BIT(i, j-1) )
            if ( rem + b[j] == a[f[i]+1] )
                f[i|(1<<(j-1))] = max(f[i|(1<<(j-1))], f[i] + 1);
            else f[i|(1<<(j-1))] = max(f[i|(1<<(j-1))], f[i]);
    }

    cout << "No\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("salary.inp", "r") ){
        freopen("salary.inp", "r", stdin);
        freopen("salary.out", "w", stdout);
    }

    int test;
    cin >> test;
    while ( test-- ) solve();

    return 0;
}
