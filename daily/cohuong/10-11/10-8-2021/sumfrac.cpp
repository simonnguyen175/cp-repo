#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll t, n, fn, gn;

struct frac{
    ll ts, ms;

    frac(){ ts = ms = 0; }
    frac(ll ts, ll ms) : ts(ts), ms(ms) {}

    frac operator + (const frac& a) const{
        ll rms = ( ms * a.ms ) / __gcd(ms, a.ms);
        ll rts = ts * rms / ms + a.ts * rms / a.ms;
        ll rgcd = __gcd(rms, rts);
        return frac(rts/rgcd, rms/rgcd);
    }

    frac operator - (const frac& a) const{
        ll rms = ( ms * a.ms ) / __gcd(ms, a.ms);
        ll rts = ts * rms / ms - a.ts * rms / a.ms;
        ll rgcd = __gcd(rms, rts);
        return frac(rts/rgcd, rms/rgcd);
    }
};

bool prime(ll x){
    for (ll i = 2; i <= sqrt(x); i ++)
        if ( x % i == 0 ) return false;
    return true;
}

int main(){
    cin >> t;
    while ( t -- ){
        cin >> n;
        for (ll i = n + 1; true; i ++)
            if ( prime(i) ) { fn = i; break;}

        for (ll i = n; true; i --)
            if ( prime(i) ) { gn = i; break; }


        ll ts = gn * fn - 2 * fn + 2 * n - 2 * gn + 2;
        ll ms = 2 * gn * fn;
        ll gcd = __gcd(ts, ms);
        cout << ts/gcd << '/' << ms/gcd << '\n';
    }

    return 0;
}
