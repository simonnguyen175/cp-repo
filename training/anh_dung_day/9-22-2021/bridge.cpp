#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
using namespace std;
const int N = 2e5 + 5;
const int MOD = 1e9 +7;

struct bridge{
	int order; ll sum;
};

int t, n, cnt[N], tt;
ll s1, s2;
pair<ll, ll> a[N];
bridge id[N];

void solve(){
	deque<int> dq;
	memset(cnt, 0, sizeof cnt);
	tt = s1 = s2 = 0;

    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i].fi >> a[i].se;
    sort(a + 1, a + n + 1);

    for(int i = 1; i <= n; i ++){
        while(dq.size() && a[i].se > a[dq.back()].se) dq.pop_back();

        if ( !dq.size() || ( dq.size() && a[dq.back()].se != a[i].se) ) id[i] = {++tt, a[i].fi};
        else{
            id[i] = {id[dq.back()].order , (id[dq.back()].sum + a[i].fi) % MOD };
            s1 = ( s1 + ( 2 * a[i].fi * id[dq.back()].sum) % MOD ) % MOD;
        }

        dq.pb(i);
    }

    for(int i = 1; i <= n; i ++) cnt[id[i].order]++;

    for(int i = 1; i <= n; i ++)
        s2 = ( s2 + (((a[i].fi * a[i].fi) % MOD ) * (cnt[id[i].order] - 1)) % MOD ) % MOD;

   cout << (s2 - s1 + MOD) % MOD << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

	cin >> t;

	while( t -- )
        solve();

    return 0;
}
