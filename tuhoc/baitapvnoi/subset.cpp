#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int n, k, ans = 0, a[N];
map<int, int> d;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("subset.inp", "r") ){
        freopen("subset.inp", "r", stdin);
        freopen("subset.out", "w", stdout);
    }

    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], d[a[i]%k] ++;

    if ( k == 1 ){ cout << 1; return 0; }

    if ( d[0] > 0 ) ans += 1;
    for (int i = 1; i < k/2; i ++)
        ans += max(d[i], d[k-i]);

    if ( k % 2 == 0 ) { if ( d[k/2] > 0 ) ans += 1; }
    else ans += max(d[k/2], d[k-k/2]);

    cout << ans;
}
