#include<bits/stdc++.h>
using namespace std;
const int N = 3e3 + 5;
const int MOD = 1e9 + 7;

string s;
int n;
int f[N][N], g[N][N], res[N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1LL * a * b % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> s;
    n = s.size();
    s = ' ' + s;

    for (int i = 1; i <= n; i ++)
    for (int j = n; j > i; j --){
        f[i][j] = add(add(f[i-1][j], f[i][j+1]), -f[i-1][j+1]);
        if ( s[i] == s[j] ) f[i][j] = add(f[i][j], add(f[i-1][j+1], 1));
    }

    for (int i = 1; i <= n; i ++) g[i][i] = 1;

    for (int i = n; i >= 1; i --)
    for (int j = i+1; j <= n; j ++){
        g[i][j] = add(add(g[i+1][j], g[i][j-1]), -g[i+1][j-1]);
        if ( s[i] == s[j] ) g[i][j] = add(g[i][j], add(g[i+1][j-1], 1));
    }

    for (int i = 1; i <= n; i ++) res[i] = add(f[i-1][i+1], 1);

    for (int i = 1; i <= n; i ++)
    for (int j = i+1; j <= n; j ++) if ( s[i] == s[j] ){
        int tmp = mul(add(f[i-1][j+1], 1), add(g[i+1][j-1], 1));
        res[i] = add(res[i], tmp);
        res[j] = add(res[j], tmp);
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++)
        ans ^= mul(res[i], i);
    cout << ans;

    return 0;
}
