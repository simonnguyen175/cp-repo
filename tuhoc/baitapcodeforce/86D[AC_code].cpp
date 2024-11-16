#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << H;
	debug_out(T...);
}

#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", debug_out(__VA_ARGS__)
#define all(x) x.begin(), x.end()
#define MP(x, y) make_pair(x, y)
#define F first
#define S second

const int MAXN = 2e5 + 10;
const int MAXA = 1e6 + 10;
const int SQRT = 450;

struct Query{
	int l, r, idx;
};

bool cmp(Query a, Query b){
	if (a.l / SQRT == b.l / SQRT) return a.r < b.r;
	return a.l / SQRT < b.l / SQRT;
}

int n, q, a[MAXN], cnt[MAXA];
ll res[MAXN];
vector<Query> Q;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);

    if ( fopen("86D.inp", "r") ){
        freopen("86D.inp", "r", stdin);
        freopen("86D.out", "w", stdout);
    }


	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= q; i++){
		int l, r; cin >> l >> r;
		Q.push_back({l, r, i});
	}

	sort(all(Q), cmp);

//	for (auto it : Q)
//        cout << it.l << ' ' << it.r << '\n';

	int ptl = 1, ptr = 0;
	ll ans = 0;
	for (auto [l, r, idx]: Q){
		while(ptr < r){
			ptr++;
			cnt[a[ptr]]++;
			ans += 1LL * (2 * cnt[a[ptr]] - 1) * a[ptr];
		}
		while(ptl < l){
			ans -= 1LL * (2 * cnt[a[ptl]] - 1) * a[ptl];
			cnt[a[ptl]]--;
			ptl++;
		}
		while(l < ptl){
			ptl--;
			cnt[a[ptl]]++;
			ans += 1LL * (2 * cnt[a[ptl]] - 1) * a[ptl];
		}
		while(r < ptr){
			ans -= 1LL * (2 * cnt[a[ptr]] - 1) * a[ptr];
			cnt[a[ptr]]--;
			ptr--;
		}
		res[idx] = ans;
	}

	for (int i = 1; i <= q; i++){
		cout << res[i] << '\n';
	}


	return 0;
}

