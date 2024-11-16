#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int t, n, a[N];

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    ll ans = 0;
    for (int i = 1; i <= n; i ++){
        ll res = a[i];
        int pre = a[i];
        for (int j = i - 1; j >= 1; j --){
            res += min(pre, a[j]);
            pre = min(pre, a[j]);
        }
        pre = a[i];
        for (int j = i + 1; j <= n; j ++){
            res += min(pre, a[j]);
            pre = min(pre, a[j]);
        }
        ans = max(ans, res);
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> t;
    while ( t -- ) solve();
}
