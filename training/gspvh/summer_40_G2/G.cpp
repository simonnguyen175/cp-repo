#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll oo = 1e18;

ll x;

ll Pow(int a, int b){
    if ( b == 1 ) return a;
    ll tmp = Pow(a, b/2);
    if ( tmp == 0 ) return 0;
    if ( b % 2 ){
        if ( tmp > oo / a ) return 0;
        if ( tmp > oo / tmp ) return 0;
        if ( tmp * tmp > oo / a ) return 0;
        return tmp * tmp * a;
    }
    else if ( tmp > oo / tmp ) return 0;
    else return tmp * tmp;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("divpow.inp", "r") ){
        freopen("divpow.inp", "r", stdin);
        freopen("divpow.out", "w", stdout);
    }

    cin >> x;

    if ( x == 1 ){
        cout << 1;
        return 0;
    }

    int res = -1;
    for (int b = 2; b <= 64; b ++){
        int lo = 2, hi = sqrt(x), a = -1;
        while ( lo <= hi ){
            int mid = ( lo + hi ) / 2;
            ll tmp = Pow(mid, b);
            if ( !tmp ) hi = mid - 1;
            else if ( tmp > x ) hi = mid - 1;
            else if ( tmp < x ) lo = mid + 1;
            else { a = mid; break; }
        }

        if ( a == -1 ) continue;

        int cnt = 0;
        for (int i = 1; i <= sqrt(a); i ++)
            if ( a % i == 0 ) cnt += 1 + ( i*i != a);

        if ( cnt == b ) res = a;
    }

    cout << res;

    return 0;
}
