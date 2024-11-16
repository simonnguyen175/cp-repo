#include<bits/stdc++.h>
#define int long long
#define BIT(x,k) ((x>>k)&1)
using namespace std;
const int oo = 1e18;

int n, k;
int a[15], l[2000];

int lcm(int a, int b){
    int g = __gcd(a, b);
    a /= g;
    if ( a > oo / b ) return 0;
    else return a * b;
}

int get(int x){
    int res = x;
    for (int i = 1; i < (1<<n); i ++) if ( l[i] ){
        if ( __builtin_popcount(i) % 2 ) res -= x/l[i];
        else res += x/l[i];
    }
    return res;
}

void solve(){
    cin >> n >> k;
    for (int i = 0; i < n; i ++)
        cin >> a[i];

    for (int i = 1; i < (1<<n); i ++){
        int g = 0;
        l[i] = 1;
        for (int j = 0; j < n; j ++) if ( BIT(i, j) )
            l[i] = lcm(l[i], a[j]);
    }

    int lo = 1, hi = 1e18, res;
    while ( lo <= hi ){
        int mid = ( lo + hi ) / 2;
        int cnt = get(mid);
        if ( cnt >= k ) res = mid, hi = mid - 1;
        else lo = mid + 1;
    }
    cout << res << '\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
