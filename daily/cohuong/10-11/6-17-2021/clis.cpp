#include<bits/stdc++.h>
#define simon "clis"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e3 + 5;

int n, m;
int a[N], b[N], dp[N];

void file(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
}

void init(){
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i ++)
        cin >> b[i];
}

void solve(){
    for (int i = 1; i <= n; i ++){
        int curLen = 0;
        for (int j = 1; j <= m; j ++){
            if ( a[i] == b[j] && curLen + 1 > dp[j] ) dp[j] = curLen + 1;
            if ( a[i] > b[j] && dp[j] > curLen ) curLen = dp[j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; i ++) ans = max(ans, dp[i]);

    cout << ans;
}

int main(){
    file();
    init();
    solve();
    return 0;
}
