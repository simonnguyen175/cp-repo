#include<bits/stdc++.h>
#define simon "daungoac"
#define ll long long
using namespace std;
const int N = 1e2 + 5;
const int MOD = 1e5;
const string opbracket = "([{";
const string clbracket = ")]}";

int n;
string s;
ll dp[N][N];

ll memo(int l, int r){
    if ( l > r ) return 1;

    ll &res = dp[l][r];
    if ( res >= 0 ) return res;

    res = 0;
    for (int x=l+1; x <= r; x+=2)
        for (int t = 0; t<3; t++)
            if ( s[l] == opbracket[t] || s[l] == '?' )
                if ( s[x] == clbracket[t] || s[x] == '?' ){
                    res += memo(l+1, x-1) * memo(x+1, r);
                    res %= MOD;
                }
    return res;
}

int main(){
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> n >> s;
    memset(dp, -1, sizeof dp);
    ll ans = memo(0, n-1);
    cout << ans;
    return 0;
}
