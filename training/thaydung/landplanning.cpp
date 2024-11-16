#include<bits/stdc++.h>
#define ll long long
using namespace std;

int m, b;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> m >> b;
    ll ans = 0;
    for (int y = 0, x; y <= b; y ++){
        x = (b - y) * m;
        ans = max(ans, 1ll * y * (y+1) / 2 * (x+1)
                     + 1ll * x * (x+1) / 2 * (y+1));
    }

    cout << ans;

    return 0;
}
