#include<bits/stdc++.h>
#define simon "cntnum"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

string l, r;
int k;
ll dp[N][12];

ll solve(string a){
    ll res = 0;
    int n = a.size();
    a = ' ' + a;

    // number of numbers have < n digits and divisor by k
    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= 9; i ++)
        dp[1][ i % k ] ++;

    for (int i = 1; i < n; i ++)
        for (int j = 0; j < k; j ++)
            for (int t = 0; t <= 9; t ++){
                dp[i][ ( j + t ) % k ] += dp[i-1][j];
                dp[i][ ( j + t ) % k ] %= MOD;
            }

    for (int i = 1; i < n; i ++)
        res = ( res + dp[i][0] ) % MOD;

    // number of numbers have = n digit ( < a ) and divisor by k
    memset(dp, 0, sizeof dp);

    for (int i = 1; i < a[1] - '0'; i ++)
        dp[1][ i % k ] ++;

    int s = a[1] - '0';

    for (int i = 2; i <= n; i ++){
        for (int j = 0; j < k; j ++)
            for (int t = 0; t <= 9; t ++){
                dp[i][ ( j + t ) % k ] += dp[i-1][j];
                dp[i][ ( j + t ) % k ] %= MOD;
            }

        for (int j = 0; j < a[i] - '0'; j ++){
            dp[i][ ( s + j ) % k ] ++;
            dp[i][ ( s + j ) % k ] %= MOD;
        }

        s = ( s + ( a[i] - '0' ) ) % k;
    }

    s = 0;

    for (int i = 1; i < a.size(); i++){
        s += a[i] - '0';
        s %= k;
    }

    if ( s == 0 ) res = ( res + dp[n][0] + 1 ) % MOD;
    else res = ( res + dp[n][0] ) % MOD;

    return res;
}

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> l >> r >> k;

    // cout << solve(l) << '\n' << solve(r) << '\n';

    int i = l.size() - 1;
    while ( true ){
        if ( l[i] >= '1' ){
            l[i] = (char) ( ( l[i] - '0' ) - 1 ) + '0';
            break;
        }
        else l[i] = '9';
        i --;
    }

    if ( l[0] == '0' ) l = l.substr(1, l.size()-1);

    // cout << l << '\n' << r << '\n';

    cout << ( solve(r) + MOD - solve(l) ) % MOD;

    return 0;
}
