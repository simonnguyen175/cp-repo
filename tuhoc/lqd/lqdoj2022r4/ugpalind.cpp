#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int MOD = 1e9 + 7;

int n, k;
string s[N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

namespace sub1{
    int dp[N][2];
    map<char, int> d;

    void solve(){
        for (int i = 1; i <= n; i ++)
            d[s[i][0]] = 1;

        dp[0][0] = 1;
        for (int i = 0; i <= (k+1)/2; i ++)
        for (int j = 0; j <= 1; j ++) if ( dp[i][j] )
            for (char c = 'a'; c <= 'z'; c ++)
                dp[i+1][j|d[c]] = add(dp[i+1][j|d[c]], dp[i][j]);

        cout << dp[(k+1)/2][1];
    }
}

namespace sub2{
    int dp[N][30][2];

    void solve(){
        for (char c = 'a'; c <= 'z'; c ++){
            if ( k % 2 == 0 && (char)c == s[1][0] && (char)c == s[1][1] )
                dp[1][c-'a'][1] = 1;
            else dp[1][c-'a'][0] = 1;
        }

        for (int i = 1; i < (k+1)/2; i ++)
        for (char c = 'a'; c <= 'z'; c ++)
        for (int j = 0; j <= 1; j ++) if ( dp[i][c-'a'][j] ){
            for (char cc = 'a'; cc <= 'z'; cc ++){
                if ( ( (char)c == s[1][0] && (char)cc == s[1][1] )
                  || ( (char)c == s[1][1] && (char)cc == s[1][0] ) )
                    dp[i+1][cc-'a'][1] = add(dp[i+1][cc-'a'][1], dp[i][c-'a'][j]);
                else dp[i+1][cc-'a'][j] = add(dp[i+1][cc-'a'][j], dp[i][c-'a'][j]);
            }
        }

        int ans = 0;
        for (int c = 'a'; c <= 'z'; c ++)
            ans = add(ans, dp[(k+1)/2][c-'a'][1]);

        cout << ans;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("upgalind.inp", "r", stdin);
    freopen("upgalind.out", "w", stdout);

    cin >> n >> k;
    bool sub1 = 1;
    for (int i = 1; i <= n; i ++){
        cin >> s[i];
        sub1 &= ( s[i].size() == 1 );
    }

    if ( sub1 ) { sub1::solve(); return 0; }
    if ( n == 1 && s[1].size() == 2 ) { sub2::solve(); return 0; }

    return 0;
}
