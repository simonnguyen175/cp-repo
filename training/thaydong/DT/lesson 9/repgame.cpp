#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e4 + 5;
const ll oo = 1e18;

int n, m;
int a[N], l[10], r[10], pw[10], nxt[300];
ll f[N][300];

int bit(int msk, int i){
    return ( msk / pw[i] ) % 3;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 0; i < m; i ++)
        cin >> l[i] >> r[i];

    pw[0] = 1;
    for (int i = 1; i <= m; i ++) pw[i] = pw[i-1] * 3;

    for (int msk = 0; msk < pw[m]; msk ++){
        nxt[msk] = m;
        for (int i = 0; i < m; i ++)
        if ( bit(msk, i) == 1 ){
            nxt[msk] = i; break;
        }
    }

    memset(f, 0x3f, sizeof f);

    f[0][0] = 0;

    for (int i = 1; i <= n; i ++){
        for (int msk = 0; msk < pw[m]; msk ++)
        for (int j = 0; j < m; j ++){
            int x = bit(msk, j);

            if ( x == 0 ){
                f[i][msk] = min(f[i][msk], f[i-1][msk]);
                if ( l[j] <= i && i <= r[j] ){
                    f[i][msk+pw[j]] = min(f[i][msk+pw[j]], f[i][msk]);
                    f[i][msk+2*pw[j]] = min(f[i][msk+2*pw[j]], f[i][msk]);
                }
            }

            if ( x == 1 ){
                if ( i <= r[j] )
                    f[i][msk] = min(f[i][msk], f[i-1][msk]);
                f[i][msk+pw[j]] = min({f[i][msk+pw[j]], f[i][msk+pw[j]], f[i-1][msk]});
            }

            if ( x == 2 )
                f[i][msk] = min(f[i][msk], f[i-1][msk]);
        }

        for (int msk = 0; msk < pw[m]; msk ++){
            f[i][msk] += 1LL * a[i] * nxt[msk];
            for (int j = 0; j < m; j ++){
                int x = bit(msk, j);
                if ( x == 1 && (i < l[j] || i > r[j]) )
                    f[i][msk] = oo;
                if ( x == 2 && i < l[j] )
                    f[i][msk] = oo;
            }
        }
    }

    ll ans = oo;
    for (int msk = 0; msk < pw[m]; msk ++)
        ans = min(ans, f[n][msk]);

    cout << ans;

    return 0;
}
