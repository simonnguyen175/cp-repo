#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e3 + 5;
const int M = 3e5 + 5;
const ll oo = 1e15;

int n, m;
ll a[N], s[M];
bool ck1, ck2;

namespace sub3{
    ll f[2005][2005];

    void dp(int x){
        for (int i = 0; i <= n; i ++)
        for (int j = 0; j <= n; j ++)
            f[i][j] = -oo;

        f[0][0] = s[x];

        for (int i = 0; i <= n; i ++)
        for (int j = 0; j <= n; j ++){
            f[i+1][j] = max(f[i+1][j], f[i][j]);
            if ( f[i][j] + a[i+1] >= 0 )
            f[i+1][j+1] = max(f[i+1][j+1], f[i][j] + a[i+1]);
        }

        for (int i = n; i >= 0; i --)
            if  ( f[n][i] >= 0 ){
                cout << i << ' ';
                return;
            }
    }

    void solve(){
        for (int i = 1; i <= m; i ++)
            dp(i);
    }
}

namespace sub1{
    int nn, base;
    ll f[N];

    void solve(){
        if ( ck1 ){
            for (int i = 1; i <= n; i ++)
                f[i] = f[i-1] + a[i];

            for (int i = 1; i <= m; i ++){
                int lo = 1, hi = n, res = 0;
                while ( lo <= hi ){
                    int mid = lo + hi >> 1;
                    if ( f[mid] + s[i] >= 0 ) res = mid, lo = mid + 1;
                    else hi = mid - 1;
                }
                cout << res << ' ';
            }
        }
        else{
            for (int i = 1; i <= n; i ++)
                if ( a[i] >= 0 ) { nn = i - 1; base = n - nn; break; }

            for (int i = nn; i >= 1; i --)
                f[i] = f[i+1] + a[i];

            for (int i = 1; i <= m; i ++){
                int lo = 1, hi = nn, res = 0;
                while ( lo <= hi ){
                    int mid = lo + hi >> 1;
                    if ( f[mid] + s[i] >= 0 ) res = mid, hi = mid - 1;
                    else lo = mid + 1;
                }
                if ( res == 0 ) cout << base << ' ';
                else cout << base + nn - res + 1 << ' ';
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("courses.inp", "r") ){
        freopen("courses.inp", "r", stdin);
        freopen("courses.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= m; i ++)
        cin >> s[i];

    ck1 = ck2 = 1;
    for (int i = 2; i <= n; i ++){
        ck1 &= ( a[i] <= a[i-1] );
        ck2 &= ( a[i] >= a[i-1] );
    }

    if ( ck1 || ck2 ) { sub1::solve(); return 0; }

    sub3::solve();

    return 0;
}
