#include<bits/stdc++.h>
#define simon "cutstr"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 3e5 + 5;
const ll MOD = 1e9 + 7;
const ll base = 31;

string s, t;
int nt, ns;
ll Pow[N], Hashs[N], Hasht, dp[N];

ll get(int l, int r){
    return ( Hashs[r] - Hashs[l-1] * Pow[r-l+1] + MOD * MOD ) % MOD;
}

void init(){
    cin >> s >> t;

    nt = t.size();
    ns = s.size();

    s = ' ' + s;
    t = ' ' + t;

    Pow[0] = 1;
    for (int i = 1; i <= ns; i ++)
        Pow[i] = Pow[i-1] * base % MOD;

    for (int i = 1; i <= ns; i ++)
        Hashs[i] = ( Hashs[i-1] * base + s[i] - 'a' + 1 ) % MOD;

    for (int i = 1; i <= nt; i ++)
        Hasht = ( Hasht * base + t[i] - 'a' + 1 ) % MOD;
}

void solve(){
    for (int i = nt; i <= ns; i ++){
        dp[i] = dp[i-1];
        if ( get(i - nt + 1, i) == Hasht )
            ( dp[i] += dp[i-nt] + 1 ) %= MOD;
    }
    cout << dp[ns];
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    init();
    solve();

    return 0;
}
