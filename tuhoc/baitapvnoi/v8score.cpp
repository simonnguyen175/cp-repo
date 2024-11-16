#include<bits/stdc++.h>
using namespace std;

int s, k, n;
int a[21][21];
bool dp[21][201][21];

int main(){
    cin >> s >> k >> n;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= k; j ++)
            cin >> a[i][j];

    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= n; i ++)
        dp[1][a[i][1]][i] = 1;

    for (int i = 2; i <= k; i ++)
    for (int j = 1; j <= s; j ++)
    for (int cur = 1; cur <= n; cur ++)
    for (int pre = 1; pre <= n; pre ++)
        if ( a[cur][i] >= a[pre][i-1] && j >= a[cur][i] )
            dp[i][j][cur] |= dp[i-1][j-a[cur][i]][pre];

    for (int i = 1; i <= n; i ++)
        if ( dp[k][s][i] ){
            vector<int> ans;
            cout << "YES" << '\n';
            ans.push_back(a[i][k]);
            s -= a[i][k];
            int cur = a[i][k];
            int id = k - 1;

            while ( s > 0 ){
                for (int j = 1; j <= n; j ++)
                    if ( dp[id][s][j] && a[j][id] <= cur ){
                        ans.push_back(a[j][id]);
                        s -= a[j][id];
                        cur = a[j][id];
                        id --;
                        break;
                    }
            }

            for (int i = ans.size()-1; i >= 0; i --) cout << ans[i] << ' ';

            return 0;
        }

    cout << "NO";

    return 0;
}
