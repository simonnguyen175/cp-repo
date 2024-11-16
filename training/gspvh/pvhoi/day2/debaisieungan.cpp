#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
using namespace std;
const int N = 1e7 + 5;
const int MOD = 998244353;

ll n, k, a, b;
int lpf[N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

void sieve(){
    for (int i = 2; i * i <= N-5; i ++) if ( !lpf[i] )
    for (int j = i * i; j <= N-5; j += i) if ( !lpf[j] )
        lpf[j] = i;

    for (int i = 2; i <= N-5; i ++) if ( !lpf[i] )
        lpf[i] = i;
}

namespace sub3{
    map<ll, int> d[35];
    vector<pi> pri;
    int dp[10][2<<15];

    void solve(){
        for (int i = 1; i <= b-a+1; i ++){
            ll cur = a + i - 1;
            while ( lpf[cur] ){
                int x = lpf[cur];
                int cnt = 0;
                while ( cur % x == 0 ) cur /= x, cnt ++;
                d[i][x] = cnt;
            }
            if ( cur != 1 ) d[i][cur] = 1;
        }

        while ( lpf[k] ){
            int x = lpf[k];
            int cnt = 0;
            while ( k % x == 0 ) k /= x, cnt ++;
            pri.pb({x, cnt});
        }
        if ( k != 1 ) pri.pb({k, 1});

        memset(dp, 0, sizeof dp);

        dp[0][0] = 1;
        for (int i = 0; i <= n; i ++)
        for (int t = 0; t < (1<<pri.size()); t ++) if ( dp[i][t] ){
            for (int j = 1; j <= b-a+1; j ++){
                int nt = t;
                for (int k = 0; k <= pri.size(); k ++)
                    if ( d[j][pri[k].fi] >= pri[k].se ) nt |= (1<<k);

                dp[i+1][nt] = add(dp[i+1][nt], dp[i][t]);
            }
        }

        cout << dp[n][(1<<pri.size())-1];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("debaisieungan.inp", "r", stdin);
    freopen("debaisieungan.out", "w", stdout);

    cin >> n >> k >> a >> b;

    sieve();

    if ( n <= 5 && b - a <= 30 ) sub3::solve();

    return 0;
}
