#include<bits/stdc++.h>
using namespace std;
const int N = 2e3;
const int MOD = 1e9 + 7;

int t, n, m;
int a[N], x[N], f[N][N], used[N], pw[N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    return a;
}

int mul(int a, int b){
    return 1LL * a * b % MOD;
}

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1, b; i <= n; i ++) cin >> b, a[i] ^= b;

    cin >> m;
    for (int i = 1; i <= m; i ++) cin >> x[i];
    x[m+1] = 0;

    memset(f, 0, sizeof f);
    f[0][0] = 1;
    for (int i = 0; i <= m; i ++)
    for (int j = 0; j <= 1024; j ++) if ( f[i][j] ){
        f[i+1][j] = 1;
        f[i+1][j^x[i+1]] = 1;
    }

    memset(used, 0, sizeof used);
    for (int i = 1; i <= n; i ++){
        for (int j = m; j >= 0; j --)
            if ( !f[j][a[i]] ){
                a[i] ^= x[j+1];
                used[j+1] = 1;
            }

        if ( a[i] ) { cout << -1 << '\n'; return; }
    }

    int ans = 0;
    for (int i = 1; i <= m; i ++)
        ans = add(ans, mul(used[i], pw[i]));

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("xor.in", "r") ){
        freopen("xor.in", "r", stdin);
        freopen("xor.out", "w", stdout);
    }

    pw[0] = 1;
    for (int i = 1; i <= 1024; i ++)
        pw[i] = mul(pw[i-1], 2);

    cin >> t;
    while ( t -- ) solve();

    return 0;
}
