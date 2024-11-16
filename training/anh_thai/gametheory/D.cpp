#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> k;
    ll ans = (n+m);
    for (int i = 1; i <= k; i ++){
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        ans += abs(u-x) + abs(v-y);
    }
    if ( ( 1LL * n * m  + k + 1 ) % 2 ){
        cout << ans - 2*(k+1);
    }
    else cout << 0;

    return 0;
}
