#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define BIT(x,k) ((x>>k)&1)
using namespace std;
const int N = 19;
const int oo = 1e9;

int n;
pi a[N];
int f[1<<N][51], cnt[1<<N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].fi;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].se;

    for (int i = 0; i < (1<<n); i ++)
    for (int j = 0; j <= 50; j ++)
        f[i][j] = oo;
    f[0][0] = 0;

    for (int t = 0; t < (1<<n); t ++)
    for (int i = 1; i <= n; i ++) if ( !BIT(t, i-1) )
        for (int j = i+1; j <= n; j ++)
            if ( BIT(t, j-1) ) cnt[t][i] ++;

    int cost, nt;

//    cerr << cnt[2][1] << '\n';

    for (int t = 0; t < (1<<n); t ++)
    for (int x = 0; x <= 50; x ++) if ( f[t][x] != oo ){
//    cerr << t << ' ' << x << " : \n";
    for (int i = 1; i <= n; i ++) if ( !BIT(t, i-1) ){
        int cost = i + cnt[t][i] - __builtin_popcount(t) - 1;

        int nt = t|(1<<(i-1));

        if ( ( cost + cnt[t][i] ) % 2 ){
            if ( a[i].se >= x ){
                f[nt][a[i].se] = min(f[nt][a[i].se], f[t][x] + cost);
//                cerr << "-> " << i << ' ' << nt << ' ' << a[i].se << ' ' << f[nt][a[i].se] << '\n';
            }
        }
        else if ( a[i].fi >= x ){
                f[nt][a[i].fi] = min(f[nt][a[i].fi], f[t][x] + cost);
//                cerr << "-> " << i << ' ' << nt << ' ' << a[i].fi << ' ' << f[nt][a[i].fi] << '\n';
        }
    }
    }

    int ans = oo;
    for (int x = 1; x <= 50; x ++)
        ans = min(ans, f[(1<<n)-1][x]);

    cout << ( ans == oo ? -1 : ans );

    return 0;
}
