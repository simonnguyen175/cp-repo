#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pll pair <long long, long long>
#define pii pair <int, int>
#define ci const int&
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void faster()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
const int nmax = 100004;
const int INF = 1e9;
int n, k;
int a[nmax], dp[102][nmax];
stack <int> f;

void cmax(int& x, const int& y)
{
    x = max(x, y);
}

void cmin(int& x, const int& y)
{
    x = min(x, y);
}

int main()
{
    faster();
    //freopen("Kblocks.inp","r",stdin);
    //freopen("Kblocks.out","w",stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) dp[1][i] = max(dp[1][i - 1], a[i]);
    a[n + 2] = 1e9;
    for(int i = 2; i <= k; ++i)
    {
        while(f.size()) f.pop();
        f.push(n + 2);
        for(int j = i; j <= n; ++j)
        {
            while(a[f.top()] < a[j])
            {
                cmin(dp[i - 1][j - 1], dp[i - 1][f.top() - 1]);
                f.pop();
            }
            if(dp[i - 1][f.top() - 1] + a[f.top()] > dp[i - 1][j - 1] + a[j]) f.push(j);
            dp[i][j] = dp[i - 1][f.top() - 1] + a[f.top()];
        }
    }
    cout << dp[k][n];
    return 0;
}
