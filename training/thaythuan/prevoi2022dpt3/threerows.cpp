#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e2 + 5;
const ll oo = 1e15;

int n, Q;
int a[4][N];
ll s[4][N], f[N], w[N][N];
struct key{
    int l, r, k;
} q[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> Q;

    for (int i = 1; i <= 3; i ++)
    for (int j = 1; j <= n; j ++){
        cin >> a[i][j];
        s[i][j] = s[i][j-1] + a[i][j];
    }

    for (int i = 1; i <= q; i ++)
        cin >> q[i].l >> q[i].r >> q[i].k;
    sort(q + 1, q + 1 + Q, [&](key a, key b){
        return a.r < b.r;
    });

    for (int i = 1; i <= n; i ++){
        for (int j = i; j <= n + 1; j ++)
            f[j] = oo;

        for (int j = 1; j <= Q; j ++){
            if ( q[j].l < i && q[j].r < i ) continue;

            if ( q[j].l <= i ) ckmn(f[q[j].r], q[j].k);
            else for (int k = i; k <= q[j].r; k ++)
                ckmn(f[q[j].r], f[k] + q[j].k);
        }

        for (int j = n; j >= i; j --)
            w[i][j] = f[j] = min(f[j], f[j+1]);
    }

    ll ans = -oo;
    for (int i = 1; i <= n; i ++)
    for (int j = i; j <= n; j ++)
        ans = min(s[1][i] + s[2][j] - s[2][i-1] + s[3][n] - s[3][j-1] - w[i][j]);

    cout << ans;

    return 0;
}
