#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;

int n;
vector<pi> b, w;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1, l, r, t; i <= n; i ++){
        cin >> l >> r >> t;
        if ( t == 1 ) w.pb({l, r});
        else b.pb({l, r});
    }

    sort (w.begin(), w.end(), [&](pi a, pi b){
        if ( a.se == b.se ) return a.fi < b.fi;
        else return a.se < b.se;
    });
    sort(b.begin(), b.end());

    multiset<int> sr;
    int ans = 0, id = 0;
    for (auto x : w){
        int l = x.fi, r = x.se;
        while ( id < b.size() && b[id].fi <= r ){
            sr.insert(b[id].se);
            id ++;
        }

        auto it = sr.lower_bound(l);
        if ( it != sr.end() ) ans ++, sr.erase(it);
    }

    cout << n - ans;

    return 0;
}
