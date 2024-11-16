#include<bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;

int n, m;
pi a[N];

bool check(ll spe){
    ll cur = 0;
    int cnt = 0;
    priority_queue<int> heap;
    for (int i = 1; i <= n; i ++){
        cur += a[i].se;
        heap.push(a[i].se);
        if ( cur > 1LL * a[i].fi * spe )
            cur -= heap.top(), heap.pop(), cnt ++;
    }
    return cnt <= m;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].se >> a[i].fi;
    sort(a + 1, a + 1 + n);

    ll lo = 0, hi = 1e14, res;
    while ( lo <= hi ){
        ll mid = lo + hi >> 1;
        if ( check(mid) ) res = mid, hi = mid - 1;
        else lo = mid + 1;
    }
    cout << res;

    return 0;
}
