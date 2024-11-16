#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll m, n;

int main(){
    cin >> m >> n;
    ll MS = 1, TS = 0;
    for (int i = 1; i <= m + 1; i ++){
        ll ms = 1, ts = 1;
        ts *= 5 * i * ( i % 2 ? -1 : 1 );
        for (int j = 0; j <= i - 2; j ++){
            ts *= (m-j), ms *= (n+m-j);
        }
        ts *= n, ms *= (n+m+1-i);
        ll gcd = __gcd(ts, ms);
        ts /= gcd, ms /= gcd;
        //cout << ts << ' ' << ms << '\n';
        ts *= MS, TS *= ms;
        MS *= ms;
        TS += ts;
        gcd = __gcd(MS, TS);
        MS /= gcd, TS /= gcd;
    }
    if ( TS * MS < 0 ) cout << '-';
    cout << abs(TS) << '/' << abs(MS);
    return 0;
}
