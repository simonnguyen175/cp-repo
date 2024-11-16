#include<bits/stdc++.h>
#define simon "robotgame"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e15;

int n;
struct point{
    int x, y;
} a[N];

namespace sub1{
    point cell[25];
    ll f[25][(1<<21)];

    bool BIT(int x, int k){
        return x&(1<<k);
    }

    ll dis(point a, point b){
        ll m = abs(a.x-b.x)+1, n = abs(a.y-b.y)+1;
        return m + n - 2;
    }

    void solve(){
        int cnt = 0;

        for (int i = 1; i <= n/2; i ++){
            cell[++cnt] = {i, 1};
            cell[++cnt] = {i, 2};
        }

        for (int i = 0; i <= n; i ++)
            for (int mask = 0; mask <= (1<<n)-1; mask ++)
                f[i][mask] = oo;

        f[0][0] = 0;
        for (int i = 0; i < n; i ++)
            for (int mask = 0; mask <= (1<<n) - 1; mask ++){
                for (int j = 0; j < n; j ++)
                if ( !BIT(mask, j) ){
                    int nmask = mask | (1<<j);
                    f[i+1][nmask] = min(f[i+1][nmask], f[i][mask] + dis(cell[i+1], a[j+1]));
                }
            }

        cout << f[n][(1<<n)-1];
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n; n *= 2;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].x >> a[i].y;
    }
    if ( n <= 20 ) sub1::solve();
    return 0;
}
