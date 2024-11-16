#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define BIT(x,k) ((x>>k)&1)
using namespace std;
const int N = 5e3 + 5;
const int M = 4e6 + 5;
const int base = 31;
const int MOD = 1e9 + 7;

int n, k;
string s[N];
bool ck1 = 1;
vector<int> Hash[N];
ll c[N][N];

namespace sub1{
    vector<int> f[30];
    ll g[30][N], dp[30][N];

    void solve(){
        for (int i = 1; i <= n; i ++)
            f[s[i][0]-'a'+1].pb(s[i].size());

        for (int i = 1; i <= 26; i ++){
            sort(f[i].begin(), f[i].end(), greater<int>());
            g[i][0] = 0;
            for (int j = 1; j < f[i].size(); j ++)
                g[i][j] = g[i][j-1] + f[i][j] * j;
        }

        for (int i = 0; i <= 26; i ++)
        for (int j = 0; j <= k; j ++){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            int mx = f[i+1].size();
            for (int t = 1; t <= min(k-j, mx); t ++)
                dp[i+1][j+t] = max(dp[i+1][j+t], dp[i][j] + g[i+1][t-1]);
        }

        cout << dp[26][k];
    }
}

int lcp(int i, int j){
    int l1 = s[i].size(), l2 = s[j].size();
    int lo = 0, hi = min(l1, l2), res = -1;
    while ( lo <= hi ){
        int mid = lo + hi >> 1;
        if ( Hash[i][mid] == Hash[j][mid] ) res = mid, lo = mid + 1;
        else hi = mid - 1;
    }

    if ( res == -1 ) return 0;
    else return res + 1;
}

void makeHash(int x){
    Hash[x].resize(s[x].size());
    Hash[x][0] = ( s[x][0] - 'a' + 1 ) % MOD;
    for (int i = 1; i < s[x].size(); i ++)
        Hash[x][i] = ( Hash[x][i-1] * base + s[x][i] - 'a' + 1 ) % MOD;
}

namespace sub2{
    ll ans = 0;

    void solve(){
        for (int i = 1; i <= n; i ++)
        for (int j = i + 1; j <= n; j ++)
            ans += c[i][j];

        cout << ans;
    }
}

namespace sub4{
    ll ans = 0;

    void solve(){
        for (int t = 0; t < (1<<n); t ++)
        if ( __builtin_popcount(t) == k ){
            ll tmp = 0;
            for (int i = 1; i <= n; i ++) if ( BIT(t, i-1) )
            for (int j = i+1; j <= n; j ++) if ( BIT(t, j-1) )
                tmp += c[i][j];
            ans = max(ans, tmp);
        }
        cout << ans;
    }
}

namespace sub3{
    ll ans = 0;
    pair<string, int> st[N];

    void solve(){
        for (int i = 1; i <= n; i ++)
            st[i] = {s[i], i};
        sort(st + 1, st + 1 + n);
        for (int i = 1; i <= n; i ++)
        for (int j = i + 1; j <= n; j ++){
            int x = st[i].second, y = st[j].second, z = st[i-1].second, t = st[j-1].second;
            ans = max({ans, c[x][y] + c[x][z] + c[y][z], c[x][y] + c[x][t] + c[y][t]});
        }
        cout << ans;
    }
}

int main(){
    if ( fopen("lcp.inp", "r") ){
        freopen("lcp.inp", "r", stdin);
        freopen("lcp.out", "w", stdout);
    }

    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> s[i];

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j < s[i].size(); j ++)
        if ( s[i][j] != s[i][j-1] )
            { ck1 = 0; break; }

    if ( ck1 ) { sub1::solve(); return 0; }

    for (int i = 1; i <= n; i ++)
        makeHash(i);

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
        c[i][j] = lcp(i, j);

    if ( k == 3 ) { sub3::solve(); return 0; }

    if ( k == n ) { sub2::solve(); return 0; }

    if ( n <= 20 ) { sub4::solve(); return 0; }

    return 0;
}
