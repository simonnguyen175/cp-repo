#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 2e5 + 5;

int t, n, k;
int h[N];
pi a[N];

bool check(int D){
    for (int i = 1; i <= n; i ++){
        a[i].fi = 1LL*D*i - h[i];
        a[i].se = 1LL*D*i + h[i];
    }
    sort(a+1, a+1+n);

    vector<ll> cont;
    for (int i = 1; i <= n; i ++){
        if ( cont.empty() || a[i].se >= cont.back() )
            cont.pb(a[i].se);
        else{
            auto it = upper_bound(cont.begin(), cont.end(), a[i].se);
            cont[it-cont.begin()] = a[i].se;
        }
    }

    return ( n - (int)cont.size() <= k );
}

void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> h[i];
    int lo = 0, hi = 1e9, res;
    while ( lo <= hi ){
        int mid = lo + hi >> 1;
        if ( check(mid) ) res = mid, hi = mid - 1;
        else lo = mid + 1;
    }
    cout << res << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> t;
    while ( t -- )
        solve();
    return 0;
}
