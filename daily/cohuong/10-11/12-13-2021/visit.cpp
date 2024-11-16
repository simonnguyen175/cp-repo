#include<bits/stdc++.h>
#define simon "visit"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int n, m;
int a[N];

bool check(ll lim){
    ll s = 0, cnt = 0;
    for (int i = 1; i <= n; i ++)
        if ( s + a[i] > lim ){
            cnt ++, s = a[i];
            if ( s > lim ) return false;
        }
        else s += a[i];
    cnt ++;
    return cnt <= m;
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> m;
    n ++, m ++;
    ll lo = 1, hi = 0, res;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], hi += a[i];

    while ( lo <= hi ){
        ll mid = lo + hi >> 1;
        if ( check(mid) ){
            res = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }

    cout << res;

    return 0;
}
