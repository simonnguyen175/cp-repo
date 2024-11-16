#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e15;

int n;
int a[N];

namespace sub2{
    ll f[1005][1005];

    void solve(){
        for (int i = 0; i <= n; i ++)
            for (int j = 0; j <= n; j ++)
                f[i][j] = -oo;

        f[0][0] = 0;

        for (int i = 0; i < n; i ++)
            for (int j = 0; j <= n; j ++){
                f[i+1][j+1] = max(f[i+1][j+1], f[i][j] + a[i+1]);
                if ( j - 1 >= 0 )
                    f[i+1][j-1] = max(f[i+1][j-1], f[i][j] - a[i+1]);
                f[i+1][j] = max(f[i+1][j], f[i][j]);
            }

        cout << f[n][0];
    }
}

namespace sub4{
    void solve(){
        ll ans = 0;
        priority_queue<ll> heap;
        for (int i = 1; i <= n; i ++){
            heap.push(a[i]); heap.push(a[i]);
            ans += heap.top() - a[i];
            heap.pop();
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

    if ( n <= 1000) sub2::solve();
    else sub4::solve();

    return 0;
}
