#include<bits/stdc++.h>
#define BIT(mask, i) (mask>>i)&1
using namespace std;

int q, n, m;
int msk[105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> q;
    while ( q -- ){
        cin >> n >> m;

        for (int i = 1; i <= n; i ++){
            int k, t = 0; cin >> k;
            for (int j = 1; j <= k; j ++){
                int x; cin >> x;
                t += (1<<(x-1));
            }
            msk[i] = t;
        }

        int ans = 0;
        for (int t = 1; t < (1<<m); t ++){
            int tt = t;
            for (int i = 1; i <= n; i ++)
                if ( (t&msk[i]) == msk[i] ){
                    for (int j = 0; j < m; j ++)
                        if ( BIT(tt, j) && BIT(msk[i], j) )
                            tt ^= (1<<j);
                }
            if ( !tt ) ans ++;
        }

        cout << ans << '\n';
    }

    return 0;
}
