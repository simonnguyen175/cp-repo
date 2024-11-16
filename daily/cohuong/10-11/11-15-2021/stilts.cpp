#include<bits/stdc++.h>
#define simon "stilts"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e6 + 5;

int n, m, k;
ll a[4005][4005], f[4005][4005], ans = 0;

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> m >> n >> k;

//    vector<vector<ll>> a; a.resize(m+5);
//    for (int i = 0; i < m + 5; i ++) a[i].resize(n+5+2*k);
//
//    vector<vector<ll>> f; f.resize(m+5);
//    for (int i = 0; i < m + 5; i ++) f[i].resize(n+5+2*k);
//	ll ans = 0;

//    ll a[m+5][n+2*k+5], f[m+5][n+2*k+5], ans = 0;

	for (int i = 1; i <= m; i ++)
        for(int j = 1; j <= n; j ++)
            cin >> a[i][j+k];

	for (int i = 1; i <= n; i ++)
        f[1][i+k] = a[1][i+k];

    deque<int> dq;
	for (int i = 2; i <= m; i ++){
        dq.clear();
        for (int j = 1; j <= n + 2 * k; j++) {
	    	while ( dq.size() && f[i-1][j] >= f[i-1][dq.back()] )
                dq.pop_back();
	    	dq.pb(j);

	    	if ( dq.front() + 2 * k + 1 <= j ) dq.pop_front();
	    	if ( j >= 2 * k + 1 ) f[i][j-k] = f[i-1][dq.front()] + a[i][j-k];
		}
	}

	for (int i = 1; i <= n; i ++)
        ans = max(ans, f[m][i+k]);

	cout << ans;

	return 0;
}

