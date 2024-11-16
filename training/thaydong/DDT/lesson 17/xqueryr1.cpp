#include<bits/stdc++.h>
#define ll long long
using namespace std;

int q, n;
multiset<ll> cont;

namespace sub1{
    void solve(){
        while ( q -- ){
            int type; ll x;
            cin >> type >> x;
            if ( type == 0 ) cont.insert(x);
            if ( type == 1 ) cont.erase(cont.find(x));
            if ( type == 2 ){
                for (auto it = cont.begin(); it != cont.end(); it ++){
                    ll u = *it; cont.erase(cont.find(u));
                    u ^= x; cont.insert(u);
                }
            }
            if ( type == 3 ){
                ll ans = 0, cnt = 0;
                for (auto it = cont.begin(); it != cont.end(); it ++){
                    ans += *it;
                    cnt ++; if ( cnt == x ) break;
                }
                cout << ans << '\n';
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> q;
    sub1::solve();
    return 0;
}
