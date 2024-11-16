#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int m, n, k;
pair<int, int> a[N];
long long bit[N];

void updatePoint(int u, int v){
    int idx = u;
    while ( idx <= max(m, n) ){
        bit[idx] += v;
        idx += idx & (-idx);
    }
}

long long getSum(int p){
    int idx = p;
    long long res = 0;
    while ( idx > 0 ){
        res += bit[idx];
        idx -= idx & (-idx);
    }
    return res;
}

void solve(int t){
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i ++)
        cin >> a[i].first >> a[i].second;

    long long ans = 0;

    memset(bit, 0, sizeof bit);
    sort(a + 1, a + 1 + k, [](pair<int, int>& u, pair<int, int>& v) {
		if (u.first == v.first) return u.second > v.second;
		return u.first > v.first;
	});

    for (int i = 1; i <= k; i ++){
        ans += getSum(a[i].second - 1);
        updatePoint(a[i].second, 1);
    }

    printf("Test case %d: %lld\n", t, ans);
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    int t; cin >> t;
	for (int i = 1; i <= t; ++i)
        solve(i);
    return 0;
}
