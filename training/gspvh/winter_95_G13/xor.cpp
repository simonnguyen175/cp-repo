#include<bits/stdc++.h>
#define int long long
#define ll long long
#define BIT(x, k) ((x>>k)&1)
using namespace std;

ll a, n;

bool ck(ll l, ll r){
    return ( r/n - (l+n-1)/n >= 0 );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("xor.inp", "r") ){
        freopen("xor.inp", "r", stdin);
        freopen("xor.out", "w", stdout);
    }

    cin >> a >> n;
    ll b = 0, cur = 0;
    for (int i = 60; i >= 0; i --) if ( BIT(a, i) ){
        if ( ck(cur + (1ll<<i), cur + (1ll<<i) + (1ll<<i) - 1) ){
            cur += (1ll<<i);
        }
        else b += (1ll<<i);
    }
    else{
        if ( !ck(cur, cur + (1ll<<i) - 1) ) b += (1ll<<i), cur += (1ll<<i);
    }
    cout << b;

    return 0;
}
