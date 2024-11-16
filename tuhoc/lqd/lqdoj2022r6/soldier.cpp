#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;

int n, k;
int p[N];

namespace sub2{
    int f[N][N];

    int get(int id){
        for (int i = 0; i <= n; i ++)
        for (int j = 0; j <= k; j ++)
            f[i][j] = 0;

        f[0][0] = 1;
        for (int i = 0; i <= n; i ++)
        for (int j = 0; j <= k; j ++) if ( f[i][j] ){
//            cout << i << ' ' << j << " -> " << i+1 << ' ' << j << '\n';
            f[i+1][j] = f[i][j];
            if ( i+1 != id && j+p[i+1] <= k ){
//                cout << i << ' ' << j << " -> " << i+1 << ' ' << j+p[i+1] << '\n';
                f[i+1][j+p[i+1]] = f[i][j];
            }
        }

        for (int i = max(0, k-p[id]); i < k; i ++)
            if ( f[n][i] ) return 1;
        return 0;
    }

    void solve(){
        for (int i = 1; i <= n; i ++)
            cout << get(i);
    }
}

namespace sub3{
    int pre[N][N], suf[N][N];
    const int MOD = 1e9 + 7;

    int add(int a, int b){
        a += b;
        if ( a >= MOD ) a -= MOD;
        if ( a < 0 ) a += MOD;
        return a;
    }

    int mul(int a, int b){
        return 1ll * a * b % MOD;
    }

    void solve(){
        pre[0][0] = 1;
        for (int i = 0; i <= n; i ++)
        for (int j = 0; j <= k; j ++){
            pre[i+1][j] = add(pre[i+1][j], pre[i][j]);
            pre[i+1][min(k, j+p[i+1])] = add(pre[i+1][min(k, j+p[i+1])], pre[i][j]);
        }

        suf[n+1][0] = 1;
        for (int i = n; i >= 1; i --)
        for (int j = 0; j <= k; j ++){
            suf[i][j] = suf[i+1][j];
            suf[i][j] = add(suf[i][j], suf[i+1][max(0, j-p[i])]);
        }

        for (int i = 1; i <= n; i ++){
            int sum = 0;
//            cout << i << " : \n";
            for (int j = 0; j <= k; j ++){
//                cout << j << ' ' << k-j << ' ' << pre[i-1][j] << ' ' << suf[i+1][k-j] << '\n';
                sum = add(sum, mul(pre[i-1][j], suf[i+1][k-j]));
            }
            if ( mul(sum, 2) == suf[1][k] ) cout << 0;
            else cout << 1;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("soldier.inp", "r", stdin);
    freopen("soldier.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> p[i];

    if ( n <= 400 ) sub2::solve();
    else
        sub3::solve();

    return 0;
}
