#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int t, n, k;
int a[N];

bool check(int x){
    vector<int> b;
    for (int i = 1; i <= x; i ++) b.pb(a[i]);
    sort(b.begin(), b.end());
    ll lim = 0;
    for (int i = 0; i < b.size(); i ++)
        if ( b[i] > lim + 1 ) return false;
        else lim += b[i];
    return lim >= k;
}

void solve(){
    cin >> n >> k;

    for (int i = 1; i <= n; i ++) cin >> a[i];

    ll lo = 1, hi = n, res = -1;
    while ( lo <= hi ){
        int mid = lo + hi >> 1;
        if ( check(mid) ){
            res = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }

    cout << res << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("riddles.inp", "r") ){
        freopen("riddles.inp", "r", stdin);
        freopen("riddles.out", "w", stdout);
    }

    cin >> t;
    while ( t -- ) solve();
    return 0;
}
