#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n;
int a[N], b[N];

namespace sub2{
    int l[N], r[N], d[N];

    void solve(){
        deque<int> dq;
        for (int i = 1; i <= n; i ++){
            while ( dq.size() && a[dq.back()] < a[i] ) dq.pop_back();
            if ( !dq.size() ) l[i] = 1;
            else l[i] = dq.back()+1;
            dq.push_back(i);
        }
        dq.clear();
        for (int i = n; i >= 1; i --){
            while ( dq.size() && a[dq.back()] < a[i] ) dq.pop_back();
            if ( !dq.size() ) r[i] = n;
            else r[i] = dq.back()-1;
            dq.push_back(i);
        }

        for (int i = 1; i <= n; i ++)
            d[l[i]]++, d[r[i]+1] --;

        int ans = 0;
        for (int i = 1; i <= n; i ++){
            d[i] += d[i-1];
            if ( d[i] ) ans ++;
        }

        cout << ans << '\n';
    }
}

namespace sub6{
    int f[5005][5005], dp[5005];

    void solve(){
        for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            f[i][j] = f[i][j-1] + (b[j] == a[i]);

        for (int i = 0; i <= n; i ++){
            int mx = 0;
            for (int j = i+1; j <= n; j ++){
                if ( a[j] > a[mx] ) mx = j;
                dp[j] = max(dp[j], dp[i] + f[mx][j] - f[mx][i]);
            }
        }

        cout << dp[n] << '\n';
    }
}

namespace sub4{
    int l[N], r[N], st[N], dp[N];
    unordered_map<int, vector<int>> pos;

    void solve(){
        deque<int> dq;
        for (int i = 1; i <= n; i ++){
            while ( dq.size() && a[dq.back()] < a[i] ) dq.pop_back();
            if ( !dq.size() ) l[i] = 1;
            else l[i] = dq.back()+1;
            dq.push_back(i);
        }
        dq.clear();
        for (int i = n; i >= 1; i --){
            while ( dq.size() && a[dq.back()] < a[i] ) dq.pop_back();
            if ( !dq.size() ) r[i] = n;
            else r[i] = dq.back()-1;
            dq.push_back(i);
        }

        for (int i = 1; i <= n; i ++){
            pos[b[i]].pb(i);
            if ( b[i] == a[i] ) st[i] = pos[b[i]].size()-1;
        }

        for (int i = 1; i <= n; i ++){
            dp[i] = dp[i-1];
            if ( pos.find(a[i]) == pos.end() ) continue;

            // dp[k] -> dp[i] ( k < i )
            int cnt = 1;
            for (int j = st[i]; j >= 0; j --){
                int k = pos[a[i]][j];
                if ( k >= l[i] ) dp[i] = max(dp[i], dp[k-1] + cnt);
                else break;
                cnt ++;
            }

            // dp[i] -> dp[k] ( k > i )
            cnt = 1;
            for (int j = st[i]+1; j < pos[a[i]].size(); j ++){
                int k = pos[a[i]][j];
                if ( k <= r[i] ) dp[k] = max(dp[k], dp[i] + cnt);
                else break;
                cnt ++;
            }
        }

        cout << dp[n] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("gianlan.inp", "r", stdin);
    freopen("gianlan.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    bool ck2 = 1;
    for (int i = 1; i <= n; i ++){
        cin >> b[i];
        if ( i > 1 ) ck2 &= ( b[i] == b[i-1] );
    }

//    cout << ck2 << '\n';

    if ( n <= 5e3 ) sub6::solve();
    else if ( ck2 ) sub2::solve();
    else
        sub4::solve();

    return 0;
}
