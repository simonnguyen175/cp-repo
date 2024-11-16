#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 5;

int n, k;
int a[N], nxt[N][2];
pi dp[N][2];

void upd(pi &a, pi b){
    if ( a.fi == b.fi ) a.se = max(a.se, b.se);
    else if ( a.fi > b.fi ) a = b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        a[i] --;
    }
    nxt[n+1][0] = nxt[n+1][1] = n+1;
    for (int i = n; i >= 1; i --){
        nxt[i][0] = nxt[i+1][0];
        nxt[i][1] = nxt[i+1][1];
        nxt[i][a[i]] = i;
    }


    // dp(i, j) xet den i thao tac loai j bat dau tai i
    // fi so thao tac it nhat
    // se vi tri gan nhat bat dau thao tac loai j^1

    for (int i = 1; i <= n; i ++)
        dp[i][0] = dp[i][1] = {n+1, 0};

    if ( a[1] == -1 ) dp[1][1] = {1, -k+1}, dp[1][0] = {1, -k+1};
    else dp[1][a[1]] = {1, -k+1};

    int ans = n + 1;
    for (int i = 1; i <= n; i ++)
    for (int j = 0; j <= 1; j ++){
        int v = dp[i][j].fi, p = dp[i][j].se;

        if ( nxt[p+k][j^1] != n+1 && nxt[p+k][j^1] >= p+k && nxt[p+k][j^1] <= i+k-1 )
            upd(dp[nxt[p+k][j^1]][j^1], {v+1, i});
        else{
            if ( i + k - 1 >= n ) { ans = min(ans, v); continue; }
            upd(dp[i+k][j], {v+1, p});
            upd(dp[i+k][j^1], {v+1, i});
        }
    }

    cout << ans;

    return 0;
}
