#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 111539786;

int n, k, mx;
string p[15];
int f[15][205][15], fail[405], Next[15][205][2];
ll dp[205][205][15];


void init(){
    cin >> n >> k;
    for (int i = 1; i <= k; i ++){
        cin >> p[i];
        int l = p[i].size();
        mx = max(mx, l);
    }
    // makeF
    memset(f, 0, sizeof f);
    for (int s1 = 1; s1 <= k; s1 ++)
        for (int len = 1; len <= p[s1].size(); len ++)
            for (int s2 = 1; s2 <= k; s2 ++){
                if ( s1 == s2 ) {f[s1][len][s1] = len; continue;}
                string t = p[s2] + '#' + p[s1].substr(0,len);
                int m = t.size();
                t = ' ' + t;

                memset(fail, 0, sizeof fail);
                for (int i = 2; i <= m; i ++){
                    int k = fail[i-1];
                    while ( k && t[k+1] != t[i] ) k = fail[k];
                    if ( t[k+1] == t[i] ) k ++;
                    fail[i] = k;
                }

                f[s1][len][s2] = fail[m];
            }

    //makeNext
    for (int i = 1; i <= k; i ++){
        for (int j = 0; j < p[i].size(); j ++)
            for (int c = 0; c <= 1; c ++){
                string t = p[i].substr(0,j) + (char) (c +'0');
                while ( t != "" && p[i].substr(0,t.size()) != t ) t.erase(0,1);
                Next[i][j][c] = t.size();
            }
        for (int c = 0; c <= 1; c ++)
            Next[i][p[i].size()][c] = p[i].size();
    }
}

void solve(){
    memset(dp, 0, sizeof dp);
    dp[0][0][1] = 1;
    for (int i = 0; i < n; i ++)
        for (int j = 1; j <= k; j ++)
            for (int d = 0; d <= p[j].size(); d ++){
                if ( !dp[i][d][j] ) continue;
                for (int c = 0; c <= 1; c ++){
                    pair<int, int> mxl; mxl.second = 1;
                    for (int t = 1; t <= k; t ++){
                        int nd = Next[t][f[j][d][t]][c];
                        if ( mxl.first < nd ){mxl.first = nd; mxl.second = t;}
                    }
                    (dp[i+1][mxl.first][mxl.second]+=dp[i][d][j])%=MOD;
                }
            }


    ll ans = 0;
    for (int i = 1; i <= k; i ++)
        for (int d = 0; d < p[i].size(); d ++)
            (ans+=dp[n][d][i])%=MOD;

    cout << ans;
}

int main(){
    init();
    solve();
    return 0;
}
