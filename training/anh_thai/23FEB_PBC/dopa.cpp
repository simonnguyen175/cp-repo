#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int n;
int pw[N], base[N], dp[N];
vector<int> divs[N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n;

    pw[0] = 1;
    for (int i = 1; i <= n; i ++)
        pw[i] = mul(pw[i-1], 26);

    for (int i = 1; i <= n; i ++)
        if ( i % 2 ) base[i] = mul(i, pw[i/2+1]);
        else base[i] = add(mul(i/2, pw[i/2]), mul(i/2, pw[i/2+1]));

    for (int i = 1; i <= n; i ++)
    for (int j = 2*i; j <= n; j += i)
        divs[j].pb(i);

    dp[1] = 26;
    for (int i = 2; i <= n; i ++){
        dp[i] = base[i];
//        cout << i << ' ' << dp[i] << '\n';
        for (int x : divs[i])
            dp[i] = add(dp[i], -mul(dp[x], i/x));
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++)
        ans = add(ans, mul(dp[i], n/i));

    cout << ans;

    return 0;
}
