#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

string k;
int d;
int x[10005];
ll f[10005][105][2];

ll calc(int i, int du, bool ok){
    if ( f[i][du][ok] != -1 ) return f[i][du][ok];

    if ( i > 10001 )
        if ( du == 0 ) return 1;
        else return 0;

    ll cnt = 0;
    for (int c = 0; c <= max(ok*9, x[i]); c ++){
        ( cnt += calc(i + 1, (du + c) % d, ok | (c < x[i])) ) %= MOD;
    }

    f[i][du][ok] = cnt;

    return cnt;
}

int main(){
    cin >> k >> d;
    memset(x, 0, sizeof x);
    for (int i = 10001, j = k.size()-1; i >= 10001 - k.size() + 1; i --, j --)
        x[i] = k[j] - '0';

    memset(f, -1, sizeof f);
    cout << ( calc(1, 0, 0) - 1 + MOD ) % MOD;

    return 0;
}
