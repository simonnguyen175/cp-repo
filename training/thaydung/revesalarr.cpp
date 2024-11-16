#include<bits/stdc++.h>
#define fi first
#define se second
#define pi pair<int, int>
#define pb push_back()
using namespace std;
const int N = 505;

int n;
int a[N], b[N];
map<pi, int> d, h;

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        cin >> b[i];

    if ( a[1] != b[1] || a[n] != b[n] )
        return cout << "NO\n", void();

    d.clear(); h.clear();
    for (int i = 1; i < n; i ++)
        d[{a[i], a[i+1]}] ++, d[{a[i+1], a[i]}] ++;
    for (int i = 1; i < n; i ++)
        h[{b[i], b[i+1]}] ++, h[{b[i+1], b[i]}] ++;

    for (auto it : d)
        if ( it.se != h[it.fi] ) return cout << "NO\n", void();

    cout << "YES\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
