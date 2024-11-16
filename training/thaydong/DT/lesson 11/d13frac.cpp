#include<bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;

int h, k;
map<int, int> d;

int id(pi x){
    pi l = {0, 1}, r = {1, 0};
    pi cur = {1, 1};
    int res = 1;
    while ( true ){
        cur = {l.fi+r.fi, l.se+r.se};
        if ( cur.fi*x.se > cur.se*x.fi ){
            r = cur;
            res = res * 2;
        }
        else if ( cur.fi*x.se < cur.se*x.fi){
            l = cur;
            res = res * 2 + 1;
        }
        else return res;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> h >> k;
    vector<int> q1, q2;
    for (int i = 1, p, q; i <= k; i ++){
        cin >> p >> q;
        int u = id({p, q});
        q1.pb(u);
    }

    sort(q1.begin(), q1.end(), greater<int>());
    q1.erase(unique(q1.begin(), q1.end()), q1.end());

    if ( q1.size() == 1 ) { cout << 0; return 0; }

    q2.pb(q1[0]/2);
    int ans = 1;
    int p1 = 1, p2 = 0;
    while ( p1 < q1.size() || p2 < q2.size() ){
        int mx;
        if ( p1 == q1.size() ) mx = q2[p2];
        else mx = max(q1[p1], q2[p2]);

        while ( p1 < q1.size() && q1[p1] == mx ) p1 ++;
        while ( p2 < q2.size() && q2[p2] == mx ) p2 ++;

        if ( p1 == q1.size() && p2 == q2.size() ) break;

        q2.pb(mx/2);

        ans ++;
    }

    cout << ans;

    return 0;
}
