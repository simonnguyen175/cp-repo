#include<bits/stdc++.h>
#define simon "timso"
#define ll long long
using namespace std;

ll x, n;
map<ll, ll> d, a;

ll conv(ll x){
    ll res = 1, tmp = x;
    while ( tmp > 0 ){
        if ( tmp % 10 != 0 ) res *= tmp % 10;
        tmp /= 10;
    }
    while ( x > 0 ){
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main(){
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> x >> n;

    ll m = 1, cir, l;
    d[x] = 1;  a[1] = x;

    while ( true ){

        x = conv(x);
        m ++;
        if ( d[x] > 0 ){
            l = d[x];
            cir = m - l;
            break;
        }
        d[x] = m;
        a[m] = x;
    }

    if ( n <= m-1 ) cout << a[n];
    else
        if ( (n - l + 1) % cir == 0 ) cout << a[l-1+cir];
        else cout << a[l-1+((n - l + 1) % cir)];
    return 0;
}
