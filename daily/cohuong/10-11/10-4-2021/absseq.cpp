#include<bits/stdc++.h>
#define simon "absseq"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;

ll p, q, k, ans;

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> p >> q >> k;

    if ( k == 1 ) { cout << p; return 0; }
    if ( k == 2 ) { cout << q; return 0; }

    for (int i = 3; i <= k; i ++){
        ans = abs(p-q);
        p = q;
        q = ans;
    }

    cout << ans;

    return 0;
}
