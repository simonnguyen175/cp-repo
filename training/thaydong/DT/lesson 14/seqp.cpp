#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int n;
int a[N];

namespace sub4{
    map<int, int> d;
    int l[N], r[N], f[N][20];
    ll ans = 0;

    int get(int l, int r){
        int k = __lg(r-l+1);
        return __gcd(f[l][k], f[r-(1<<k)+1][k]);
    }

    void solve(){
        for (int i = 1; i <= n; i ++) d[a[i]] = 0;
        for (int i = 1; i <= n; i ++)
            l[i] = d[a[i]] + 1, d[a[i]] = i;
        for (int i = 1; i <= n; i ++) d[a[i]] = n+1;
        for (int i = n; i >= 1; i --)
            r[i] = d[a[i]] - 1, d[a[i]] = i;

        for (int i = 1; i <= n; i ++) f[i][0] = a[i];
        for (int j = 1; j <= 17; j ++)
        for (int i = 1; i <= n-(1<<j)+1; i ++)
            f[i][j] = __gcd(f[i][j-1], f[i+(1<<(j-1))][j-1]);

        for (int i = 1; i <= n; i ++){
            int lo = l[i], hi = i-1, lef = i;
            while ( lo <= hi ){
                int mid = lo + hi >> 1;
                if ( get(mid, i-1) % a[i] == 0 ) lef = mid, hi = mid - 1;
                else lo = mid + 1;
            }

            lo = i+1, hi = r[i];
            int rig = i;
            while ( lo <= hi ){
                int mid = lo + hi >> 1;
                if ( get(i+1, mid) % a[i] == 0 ) rig = mid, lo = mid + 1;
                else hi = mid - 1;
            }

            int cl = i-lef, cr = rig-i;
            ans += cl + cr + 1ll * cl * cr;
        }

        cout << ans;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    sub4::solve();

    return 0;
}
