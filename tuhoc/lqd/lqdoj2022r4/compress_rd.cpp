#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define int long long
#define pb push_back
#define db(val) "[" #val " = " << (val) << "] "
using namespace std;
const ll mod = 20;
const int maxn = 7;
const int INF = 100;
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

int get(int l, int r) {
    return l + mt() % (r - l + 1);
}

int s[maxn];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen(".INP", "r", stdin);
    // freopen("inputf.in", "w", stdout);
    int t = 1;
    int n = get(5, maxn), k = 2, p = 2;
    cout << t << '\n' << n << ' ' << k << ' ' << p << '\n';
    vector<int> v;
    for (int i = 1; i <= n; i++)
        v.pb(i);
    shuffle(v.begin(), v.end(), mt);
    for (int i = 0; i < n - k + 1; i++) {
        for (int j = i; j < i + k; j++)
            s[i] += v[j];
        cout << s[i] << ' ';
    }
}
