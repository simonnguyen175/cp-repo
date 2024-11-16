#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N = 2e5 + 5;

int n, k;
ll l;
int a[N], d[N];

bool check(int x){
    int s = 0;
    ll cnt = 0;
    d[0] = 0;
    for (int i = 1; i <= n; i ++){
        if ( a[i] <= x ) s ++;
        d[s] = i;
        if ( s >= k ) cnt += d[s-k]+1;
    }
    return cnt >= l;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k >> l;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    int lo = 1, hi = n, res = n;
    while ( lo <= hi ){
        int mid = lo + hi >> 1;
        if ( check(mid) ) res = mid, hi = mid - 1;
        else lo = mid + 1;
    }

    cout << res << '\n';

    return 0;
}
