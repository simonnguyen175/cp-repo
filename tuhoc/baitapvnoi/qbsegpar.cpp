#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 2e5 + 5;
const int oo = 1e9;

int n, m, k;
int a[N], bit[2][N];
vector<int> b;

void update(int t, int u, int v){
    for (; u >= 1; u -= u&-u)
        if ( !t ) bit[0][u] = min(bit[0][u], v);
        else bit[1][u] = max(bit[1][u], v);
}

int get(int t, int u){
    int res = ( t ? -oo : oo );
    for (; u <= n+1; u += u&-u)
        if ( !t ) res = min(res, bit[0][u]);
        else res = max(res, bit[1][u]);
    return res;
}

int id(int x){
    return lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
}

bool check(int m){
    for (int i = 1; i <= n+1; i ++) bit[0][i] = oo;
    for (int i = 1; i <= n+1; i ++) bit[1][i] = -oo;

    update(0, id(a[0]), 0); update(1, id(a[0]), 0);

    int mi = oo, ma = -oo;
    for (int i = 1; i <= n; i ++){
        int cur = id(a[i]);
        int tmp = lower_bound(b.begin(), b.end(), a[i]-m) - b.begin() + 1;
        mi = get(0, tmp)+1, ma = get(1, tmp)+1;
        update(0, cur, mi); update(1, cur, ma);
    }
    return mi <= k && k <= ma;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        a[i] += a[i-1];
        b.pb(a[i]);
    }
    b.pb(0);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    cerr << check(-8);

//    int lo = -oo, hi = oo, res;
//    while ( lo <= hi ){
//        int mid = ( lo + hi ) / 2;
//        if ( check(mid) )
//            res = mid, hi = mid - 1;
//        else lo = mid + 1;
//    }
//    cout << res;

    return 0;
}
