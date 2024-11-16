#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("dn.inp", "r", stdin);
    freopen("dn.out", "w", stdout);

    long long p, q, n;
    cin >> p >> q >> n;

    long long tmp = sqrt(p);
    if ( tmp * tmp == p )
    cout << (long long)sqrt(q) - tmp + 1;
    else cout << (long long)sqrt(q) - tmp;

    return 0;
}
