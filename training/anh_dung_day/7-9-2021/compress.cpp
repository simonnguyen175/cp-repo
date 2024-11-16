#include<bits/stdc++.h>
using namespace std;
const int N = 8e3 + 5;

string s;
int n, f[N][N], fail[N], dp[N];

int scs(int x){
    int res = 0;
    while ( x > 0 ) res ++, x /= 10;
    return res;
}

void init(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> s;
    n = s.size();
    s = ' ' + s;
    for (int i = 1; i <= n; i ++){
        string t = "";
        for (int j = i; j <= n; j ++) t += s[j];
        int m = t.size();
        t = ' ' + t;

        // kmp
        fail[1] = 0;
        int k = 0;
        for (int j = 2; j <= m; j ++){
            while ( k > 0 &&  t[k + 1] != t[j] ) k = fail[k];
            if ( t[k+1] == t[j] ) k ++;
            fail[j] = k;
        }

        // make f[][]
        for (int j = 1; j <= m; j ++){
            int lenSubstr = j - fail[j];
            if ( j % lenSubstr == 0 ) f[i][i+j-1] = scs(j/lenSubstr) + lenSubstr;
            else f[i][i+j-1] = 1 + j;
        }
    }

    cout << f[1][6] << '\n';
}

void solve(){
    for (int i = 1; i <= n; i ++)
        dp[i] = INT_MAX;
    dp[0] = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = i; j >= 1; j --)
            dp[i] = min(dp[i], dp[j-1] + f[j][i]);
    cout << dp[n];
}

int main(){
    init();
    solve();
    return 0;
}
