#include<bits/stdc++.h>
#define simon "cutseq"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int n, q;
ll a[N], f[N];

void solve(int l, int r, int x){
    for (int i = l; i <= r; i ++) a[i] += x;

    f[1] = 0;
    f[2] = abs(a[2] - a[1]);

    for (int i = 3; i <= n; i ++){
        if ( a[i] >= a[i-1] && a[i-1] >= a[i-2] ) f[i] = f[i-1] + a[i] - a[i-1];
        if ( a[i] <= a[i-1] && a[i-1] <= a[i-2] ) f[i] = f[i-1] + a[i-1] - a[i];
        if ( a[i] >= a[i-1] && a[i-1] <= a[i-2] ) f[i] = max(f[i-2] + a[i] - a[i-1], f[i-1]);
        if ( a[i] <= a[i-1] && a[i-1] >= a[i-2] ) f[i] = max(f[i-2] + a[i-1] - a[i], f[i-1]);
    }

    cout << f[n] << '\n';
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> n >> q;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= q; i ++){
        int l, r, x;
        cin >> l >> r >> x;
        solve(l, r, x);
    }
    return 0;
}
