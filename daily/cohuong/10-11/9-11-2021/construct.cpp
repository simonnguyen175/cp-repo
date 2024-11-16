#include <bits/stdc++.h>
#define simon "construct"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int t, m, n, a[N], s[N];
ll res[N];

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> t;
    while ( t-- ){
        cin >> n >> m;
        a[0] = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            if (a[i] > a[i - 1])
                s[i] = a[i] - a[i - 1];
            else s[i] = 0;
        }

        for (int i = 1; i <= n; i++)
            res[i] = res[i - 1] + s[i];

        int type, l, r, k;
        for (int i = 1; i <= m; i++){
            cin >> type >> l >> r;
            if (type == 2)
                cout << res[r] - res[l] + a[l] << '\n';
            else{
                cin >> k;
                for (int i = l; i <= r; i++) a[i] += k;
                for (int i = 1; i <= n; i++) {
                    if (a[i] > a[i - 1])
                        s[i] = a[i] - a[i - 1];
                    else
                        s[i] = 0;
                    res[i] = res[i - 1] + s[i];
                }
            }
        }
    }

    return 0;
}
