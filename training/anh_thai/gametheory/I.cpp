#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n, m, k, x, y;
    for (int t = 1; t <= 5; t ++){
        cin >> n >> m >> k;
        ll g = 0;
        for (int i = 1; i <= k; i ++)
            cin >> x >> y, x--, y --, g ^= x ^ y;
        cout << ( !g ? "NO\n" : "YES\n" );
    }

    return 0;
}
