#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("charge.inp", "r") ){
        freopen("charge.inp", "r", stdin);
        freopen("charge.out", "w", stdout);
    }

    int test;
    cin >> test;
    while ( test -- ){
        ll k;
        cin >> k;
        vector<ll> cont;
        ll cur = 1;
        cont.pb(cur);
        while ( cur * 2 <= k ){
            cur *= 2;
            cont.pb(cur);
        }
        cout << cont.size() << '\n';
        for (ll x : cont) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}
