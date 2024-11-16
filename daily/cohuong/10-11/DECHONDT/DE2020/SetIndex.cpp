#include<bits/stdc++.h>
#define simon "setindex"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 3e2 + 5;

int n, m;
int a[N][N];

namespace sub1{
    int BIT(int mask, int k){
        return (mask>>k)&1;
    }

    void solve(){
        int mxn = (1<<n)-1, mxm = (1<<m) - 1;
        ll ans = 0;

        for (int tn = 1; tn <= mxn; tn ++)
        for (int tm = 1; tm <= mxm; tm ++){
            int tmp = 0;
            for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= m; j ++)
                if ( BIT(tn, i-1) && BIT(tm, j-1) ) tmp += a[i][j];
            if ( tmp % 2 ) ans ++;
        }

        cout << ans;
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++)
        cin >> a[i][j];
    if ( n + m <= 20 ) sub1::solve();
    return 0;
}
