#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, t[1000005], s1 = 0, s = 0;
void in()
{
	cin >> n;
	for(int i = 1; i<= n; ++i) cin >> t[i];
}
void solve()
{
	sort(t + 1, t + n + 1);
	for(int i = 1; i<= n - 1; ++i) s1 += t[i];
	for(int i = 1; i<= n; ++i) s += t[i];
	if(s1 <= t[n]) cout << 2 * t[n];
	else cout << s;
}
#undef int
int main()
{
	ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
	freopen("ReadBooks.inp", "r", stdin);
	freopen("ReadBooks.out", "w", stdout);
	in();
	solve();
	return 0;
}
