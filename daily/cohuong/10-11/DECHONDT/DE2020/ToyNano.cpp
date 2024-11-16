#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e3 + 5;
const int oo = 1e15;

int n;
struct robot{
    ll h, p;
    bool operator < (const robot& a){
        if ( h + p == a.h + a.p ) return h < a.h;
        return h + p < a.h + a.p;
    }
} a[N];
ll f[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("ToyNano.inp", "r", stdin);
    freopen("ToyNano.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].h >> a[i].p;
    sort(a + 1, a + 1 + n);

    for (int i = 0; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            f[i][j] = oo;

    f[0][0] = 0;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++){
        f[i][j] = f[i-1][j];
        if ( a[i].h >=  f[i-1][j-1] )
            f[i][j] = min(f[i][j], f[i-1][j-1] + a[i].p);
    }

    for (int i = n; i >= 1; i --)
        if ( f[n][i] != oo ){
            cout << i;
            return 0;
        }
}
