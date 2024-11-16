#include<bits/stdc++.h>
#define BIT(x, k) ((x>>k)&1)
#define fi first
#define se second
#define pi pair<int, int>
using namespace std;
const int N = 1e3 + 5;
const int oo = INT_MAX;

int n, m;
char a[N][15];
int dp[N][(1<<10)+5];
vector<pi> cmsk[N];

int getcost(int i, int msk){
    int cost = 0;
    for (int j = 0; j < m; j ++){
        if ( a[i][j] == '#' && BIT(msk, j) ){
            if ( j == 0 ) cost ++;
            else if ( a[i][j-1] == '.' || !BIT(msk, j-1) ) cost ++;
        }
    }
    return cost;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i ++)
    for (int j = 0; j < m; j ++)
        cin >> a[i][j];

    for (int i = 0; i < n; i ++)
    for (int msk = 0; msk < (1<<m); msk ++){
        bool ck = 1;
        for (int j = 0; j < m; j ++)
            if ( a[i][j] == '.' && !BIT(msk, j) ){
                ck = 0;
                break;
            }

        if ( ck ) cmsk[i].push_back({msk, getcost(i, msk)});
    }

    for (int i = 0; i < n; i ++)
    for (auto it : cmsk[i])
        dp[i][it.fi] = oo;

    for (auto it : cmsk[0]){
        dp[0][it.fi] = it.se + m - __builtin_popcount(it.fi);
    }



    for (int i = 1; i < n; i ++){
        for (auto it : cmsk[i]){
            int mski = it.fi, c = it.se;
            for (auto jt : cmsk[i-1]){
                int mskj = jt.fi;
                dp[i][mski] = min(dp[i][mski], dp[i-1][mskj] + c + __builtin_popcount(mskj^(mskj&mski)));
            }
        }
    }

    int ans = oo;
    for (auto it : cmsk[n-1]){
        ans = min(ans, dp[n-1][it.fi]);
    }

    cout << ans;

    return 0;
}
