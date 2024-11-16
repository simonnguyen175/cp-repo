#include <bits/stdc++.h>
#define f(i,a,b) for(int i = a;i <= b;++i)
#define int long long
#define ll long long
#define pii pair<int,int>
#define piii pair<int , pii>
#define piiii pair <pii , pii>
#define F first
#define S second
#define task "nhuhieu193"
#define mod 1000000007
#define endl '\n'
#define minimize(x,y) x = (x > y ? y : x)
#define maximize(x,y) x = (x < y ? y : x)
using namespace std;
const int maxn = 100005;

int gcd(int x , int y) {
    return y ? gcd(y , x % y) : x;
}

string Y = "YES\n" , N = "NO\n" , Al = "Alice\n" , Bo = "Bob\n";

ll POWW(ll t , ll x) {
    if (x == 0) return 1;
    ll B = POWW(t , x / 2);
    ll C = B * B % mod;
    if (x & 1) C = C * t % mod;
    return C;
}

int n,m,k;

/// Author : CBN_K28_nhuhieu193

/// welcome to my amazing code !!!

int a[maxn];

int dp[105][105][105];

void add(int &x , int y) {
    x += y;
    if (x >= 2023) x -= 2023;
}

void process() {
    cin >> n;
    f(i,1,n) cin >> a[i];
    sort(a + 1 , a + n + 1);
    f(i,1,n) dp[0][i][i] = 1;
    f(i,1,n - 1) f(j,i + 1 , n) if (gcd(a[i] , a[j]) == 1) dp[1][i][j] = 1;
    f(u,1,n - 1) {
        f(i,1,n) f(j,i + 1 , n) if (dp[u][i][j]) {
            f(k,j + 1 ,n) if (dp[1][j][k]) add(dp[u + 1][i][k] , dp[u][i][j]);
        }
    }
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int x,y,k;
        cin >> x >> y >> k;
        x = lower_bound(a + 1 , a + n + 1 , x) - a;
        y = lower_bound(a + 1 , a + n + 1 , y) - a;
        cout << dp[k][x][y] << '\n';
    }

}

/// This is end of my solution.

int32_t main() {
    ios_base::sync_with_stdio(false);
//    freopen(task".inp","r",stdin);
//    freopen(task".out","w",stdout);
    cin.tie(0);
    int ntest = 1;
//    cin >> ntest;
    while (ntest--) {
        process();
    }

}
/// range maxn , memory
/// long long , mod
/// implement
/// file
/// reset testcase
