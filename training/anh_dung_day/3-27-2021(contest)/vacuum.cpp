#include <bits/stdc++.h>
#define x first
#define y second
#define pi pair<int, int>
#define sz(a) ((a).size())
#define pb push_back
#define mp make_pair
#define FOR(i, a, b) for(int i=a, _n=b; i<=_n; ++i)
#define FORD(i, a, b) for(int i=a, _n=b; i>=_n; --i)
using namespace std;

const int N = 105;

int n, k, a[N][N];
vector<pi> vec;

int main()
{
    ios::sync_with_stdio();
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) FOR(j, 1, n) cin >> a[i][j];

    FOR(i, 1, (n+1)/2) {
        FOR(j, i, n-i) if (!a[i][j]) vec.pb(mp(i, j));
        FOR(j, i, n-i) if (!a[j][n-i+1]) vec.pb(mp(j, n-i+1));
        FORD(j, n-i+1, i+1) if (!a[n-i+1][j]) vec.pb(mp(n-i+1, j));
        FORD(j, n-i+1, i+1) if (!a[j][i]) vec.pb(mp(j, i));
    }
    if (n&1) {
        int i = (n+1) / 2;
        if (!a[i][i]) vec.pb(mp(i, i));
    }

    FORD(i, sz(vec)-2, 1) vec.pb(vec[i]);

    k = k % sz(vec);
    cout << vec[k].x <<' ' << vec[k].y << endl;
}
