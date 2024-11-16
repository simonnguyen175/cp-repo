#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll q, a, b, k;

ll solve(ll a, ll b, ll k){
    ll t=(b-a)/k;
    ll res= a + t*a + k*t*(t+1)/2;
    return res;
}

int main(){
    freopen("QuerySC.inp","r",stdin);
    freopen("QuerySC.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> q;
    for (ll i=1; i<=q; i++){
        cin >> a >> b >> k;
        cout << solve(a,b,k) <<'\n';
    }
    return 0;
}

