#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;

int n, k;
int a[N], sum[N];

bool check(int loops, int last){
    return ( loops * n + last + 1 ) * ( loops * n + last ) >= 2 * ( loops * sum[n] + sum[last] + k );
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("nhanpham.inp", "r")  ){
        freopen("nhanpham.inp", "r", stdin);
        freopen("nhanpham.out", "w", stdout);
    }

    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> a[i], sum[i] = sum[i-1] + a[i];
        if ( (i+1)*i / 2 >= sum[i] + k ) return cout << i, 0;
    }

    int ans = LLONG_MAX;
    for (int i = 1; i <= n; i ++){
        int lo = 0, hi = 3e9/n;
        while ( lo <= hi ){
            int mid = ( lo + hi ) / 2;
            if ( check(mid, i) ) ans = min(ans, mid*n + i), hi = mid - 1;
            else lo = mid + 1;
        }
    }

    if ( ans == LLONG_MAX ) cout << -1;
    else cout << ans;

    return 0;
}
