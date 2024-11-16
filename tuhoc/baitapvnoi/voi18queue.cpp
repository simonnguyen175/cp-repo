#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int t, n, m;
int a[N], b[N];
set<int> pos;
vector<pi> cont;

bool check(int x){
    cont.clear();
    for (int i = 1; i <= x; i ++) cont.pb({b[i], a[i]});
    sort(cont.begin(), cont.end());

    pos.clear();
    for (int i = 1; i <= m; i ++) pos.insert(i);

    for (auto x : cont){
        int l = x.se, r = x.fi;
        auto it = pos.lower_bound(l);
        if ( it == pos.end() ) return false;
        if ( *it > r ) return false;
        pos.erase(*it);
    }

    return true;
}

void solve(){
    cin >> m >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i] >> b[i];
    }

    int lo = 1, hi = n, res = 0;
    while ( lo <= hi ){
        int mid = lo + hi >> 1;
        if ( check(mid) ) res = mid, lo = mid + 1;
        else hi = mid - 1;
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
