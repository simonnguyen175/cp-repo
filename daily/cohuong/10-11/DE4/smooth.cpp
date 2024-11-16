#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;

int n, k;
int a[N], f[N];

bool check(int x){
    for (int i = 1; i <= n; i ++) f[i] = n + 1;
    f[1] = 0;

    if ( n - 1 <= k ) return true;

    for (int i = 2; i <= n; i ++){
        f[i] = i - 1;
        for (int j = i - 1; j >= 1; j --)
            if ( abs(a[i]-a[j]) <= 1LL * x * (i-j) )
                f[i] = min(f[i], f[j] + i-j-1);
        if ( f[i] + n - i <= k ) return true;
    }

    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("smooth.in", "r") ){
        freopen("smooth.in", "r", stdin);
        freopen("smooth.out", "w", stdout);
    }

    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    int lo = 0, hi = 0, res;
    for (int i = 1; i < n; i ++)
        hi = max(hi, abs(a[i+1]-a[i]));

    while ( lo <= hi ){
        int mid = lo + (hi-lo)/2;
        if ( check(mid) ) res = mid, hi = mid - 1;
        else lo = mid + 1;
    }

    cout << res;

    return 0;
}
