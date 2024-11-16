#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 5;

int n;
int a[N];

/// sub2
int f[505][505];
namespace sub2{
    void solve(){
        for (int i = 1; i <= n; i ++)
        for (int j = i-1; j >= 1; j --)
            f[i][j] = 0;

        int ans = 1;
        for(int i = 1; i <= n; i ++){
            for (int j = i-1; j >= 1; j --) if ( a[i] != a[j] ){
                f[i][j] = 2;
                for (int k = j-1; k >= 1; k --) if ( a[k] != a[j] && a[k] != a[i] )
                    f[i][j] = max(f[i][j], f[j][k] + 1);
                ans = max(ans, f[i][j]);
            }
        }

        cout << ans << '\n';
    }
}

/// sub5
map<int, int> dp[N];
namespace sub5{
    void solve(){
        for (int i = 1; i <= n; i ++) dp[i].clear();

        int ans = 1;
        vector<int> cur;
        for (int i = 1; i <= n; i ++){
            /// cap nhat cur
            int pos = -1;
            for (int j = 0; j < cur.size(); j ++)
                if ( a[cur[j]] == a[i] ){
                    pos = j; break;
                }

            if ( pos != -1 ) cur.erase(cur.begin() + pos);
            else if ( cur.size() == 6 ) cur.erase(cur.begin());

            /// cap nhat dp
            dp[i][i] = 1;
            for (int j = 0; j < cur.size(); j ++){
                for (auto it : dp[cur[j]]) if ( a[it.fi] != a[i] )
                    dp[i][cur[j]] = max(dp[i][cur[j]], it.se + 1);
            }

            cur.push_back(i);

            for (auto it : dp[i]){
                ans = max(ans, it.se);
            }
        }

        cout << ans << '\n';
    }
}

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

//    if ( n <= 500 ) sub2::solve();
//    else
        sub5::solve();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
