#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
using namespace std;
const int N = 1e3 + 5;

int n, m = 0;
ll C, ans = -1;
pi a[4][N], b[N*N], c[N*N];
ll mx[N*N];

int tknp(ll key){
    int lo = 1, hi = m, res = 0;
    while ( lo <= hi ){
        int mid = ( lo + hi ) / 2;
        if ( c[mid].fi <= key ){
            res = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("smartcomp.inp", "r", stdin);
    freopen("smartcomp.out", "w", stdout);

    cin >> n >> C;
    for (int i = 0; i <= 3; i ++)
    for (int j = 1; j <= n; j ++)
        cin >> a[i][j].fi >> a[i][j].se;

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++){
            b[++m] = {a[0][i].fi + a[1][j].fi, a[0][i].se + a[1][j].se};
            c[m] = {a[2][i].fi + a[3][j].fi, a[2][i].se + a[3][j].se};
        }

    sort(b + 1, b + 1 + m);
    sort(c + 1, c + 1 + m);

    for (int i = 1; i <= m; i ++)
        mx[i] = max(mx[i-1], c[i].se);

    for (int i = 1; i <= m; i ++)
        if ( b[i].fi <= C ){
            int pos = tknp(C-b[i].fi);
            if ( pos > 0 )
                ans = max(ans, b[i].se + mx[pos]);
        }

    cout << ans;

    return 0;
}
