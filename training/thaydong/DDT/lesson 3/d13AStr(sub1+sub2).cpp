#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 111539786;
const int N = 1e5 + 5;

int n;
string s;
ll Next[10][55], f[N][10];

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    while (cin >> n >> s){
        memset(Next, 0, sizeof Next);
        for (int i = 1; i <= n; i ++)
            for (int j = 0; j <= s.size(); j ++)
                f[i][j] = 0;
        for (int i = 0; i <= s.size() - 1; i ++)
            for (char c = '0'; c <= '1'; c ++){
                string p = s.substr(0, i) + c;
                while ( p != "" && s.substr(0, p.size()) != p ) p.erase(0, 1);
                Next[i][c] = p.size();
            }

        for (char c = '0'; c <= '1'; c ++)
            Next[s.size()][c] = s.size();

        f[0][0] = 1;

        for (int i = 0; i < n; i ++)
            for (int d = 0; d <= s.size(); d ++)
                for (char c = '0'; c <= '1'; c ++)
                    f[i+1][Next[d][c]] = (f[i+1][Next[d][c]] + f[i][d])%MOD;
        ll ans = 0;
        for (int i = 0; i <= s.size() - 1; i ++)
            ans = (ans + f[n][i]) % MOD;

        cout << ans << '\n';
    }

    return 0;
}
