#include<bits/stdc++.h>
#define BIT(x,k) ((x>>k)&1)
using namespace std;
const int N = 5e4 + 5;
const int MOD = 1e9 + 7;

int n, q;
int a[N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

namespace sub1{
    int id[N];

    void solve(){
        while ( q -- ){
            int type, l, r, s;
            cin >> type;
            if ( type == 1 ) cin >> l >> r, a[l] = r;
            else{
                cin >> l >> r >> s;
                for (int i = l; i <= r; i ++)
                    id[i] = i-l+1;
                int res = 0;
                for (int t = 0; t < (1<<(r-l+1)); t ++){
                    int cur = 0;
                    for (int i = l; i <= r; i ++) if ( BIT(t, i-l) )
                        cur ^= a[i];
                    if ( cur == s ) res ++;
                }
                cout << res << '\n';
            }
        }
    }
}

namespace sub2{
    int f[1005][1005];

    void solve(){
        f[0][0] = 1;
        for (int i = 0; i <= n; i ++){
            for (int t = 0; t <= 1000; t ++) f[i+1][t] = f[i][t];
            for (int t = 0; t <= 1000; t ++)
                f[i+1][t^a[i+1]] = add(f[i+1][t^a[i+1]], f[i][t]);
        }

        while ( q -- ){
            int type, l, r, s;
            cin >> type >> l >> r >> s;
            cout << f[r][s] << '\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("xorseg.inp", "r", stdin);
    freopen("xorseg.out", "w", stdout);

    cin >> n >> q;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    if ( n <= 20 && q <= 20 ) { sub1::solve(); return 0; }
    sub2::solve();

    return 0;
}
