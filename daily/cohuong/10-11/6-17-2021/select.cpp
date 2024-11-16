#include<bits/stdc++.h>
#define simon "select"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 1e6 + 5;

int n;
ll col[N][5], dp[N][5];

void file(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
}

void init(){
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> col[i][1];
    for (int i = 1; i <= n; i ++) cin >> col[i][2];
}

ll getsum(int i, int mask){
    ll res = 0;
    bitset<2> b;
    b = bitset<2> (mask);
    for (int j = 0; j < b.size(); j ++)
        if ( b[j] ) res += col[i][j+1];
    return res;
}

void solve(){
    for (int i = 1; i <= n; i ++)
        for (int curmask = 0;  curmask <= 2; curmask ++)
            for (int premask = 0; premask <= 2; premask ++)
                if ( ( curmask & premask ) == 0 )
                    dp[i][curmask] = max(dp[i][curmask], dp[i-1][premask] + getsum(i, curmask));

    ll ans = 0;
    for (int i = 0; i <= 2; i ++)
        ans = max(ans, dp[n][i]);

    cout << ans;
}

int main(){
    file();
    init();
    solve();
    return 0;
}
