#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 105;

ll n, p[N], k[N], f[N][100005] ;
pair<ll, ll> a[N];

ll solve(ll m , ll b){
	if (b == 0) return 0;
	if (m == 0) return 1 ;
	if (b <= 1e5 && f[m][b] != -1) return f[m][b];

	ll cnt = 0 , q = 1;
	for (int i = 0 ; i <= k[m] ; i++){
		cnt += solve(m - 1 , b / q);
		q *= p[m];
		if (b < q) break;
	}

	if (b <= 1e5) f[m][b] = cnt;
	return cnt;
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> n;
    for (int i = 1 ; i <= n ; i++)
        cin >> a[i].fi >> a[i].se;
    sort(a + 1 , a + n + 1);
    for (int i = 1 ; i <= n ; i++)
        p[i] = a[i].fi , k[i] = a[i].se;
    memset(f , -1 , sizeof (f));
    for (int i = 1; i <= 3; i ++){
        ll x , y;
        cin >> x >> y;
        cout << solve(n , y)  - solve(n , x - 1) << '\n';
    }
}
