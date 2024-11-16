#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 5e5 + 5;

string s;
int n, pre[N];
pair<int, int> z[N];

void makeZ(){
    n = s.size();
    s = ' ' + s;
    z[1].se = 1;
    for (int i = 2, l = 1, r = 1; i <= n; i ++){
        z[i].se = i;
        if ( i <= r )
            z[i].fi = min(z[i-l+1].fi, r - i + 1);
        while ( i + z[i].fi <= n && s[z[i].fi+1] == s[i+z[i].fi] )
            z[i].fi ++;
        if ( z[i].fi == 0 ) continue;
        if ( i + z[i].fi - 1 > r )
            l = i, r = i + z[i].fi - 1;
    }
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> s;
    makeZ();
    sort(z + 1, z + 1 + n, greater<pair<int, int>>());
    multiset<int> Set;
    multiset<int> kc;
    Set.insert(1), Set.insert(n+1); kc.insert(n);
    int ans = n;
    for (int i = 1; i <= n; i ++){
        if ( z[i].fi == 0 ) break;
        auto rit = Set.upper_bound(z[i].se);
        auto lit = Set.lower_bound(z[i].se);  -- lit;
        //cout << *lit << ' ' << *rit << ' ';
        int l = *rit - *lit; //cout << l << ' ' ;
        auto it = kc.find(l);
        if ( it != kc.end() ) kc.erase(it); //cout << *it << '\n';
        kc.insert(z[i].se-*lit), kc.insert(*rit-z[i].se);
        //cout << z[i].se-*lit << ' ' << *rit-z[i].se << '\n';
        it = kc.end(); -- it;
        //cout << *it << '\n' << '\n';
        if ( *it <= z[i].fi ) ans = z[i].fi;
        Set.insert(z[i].se);
    }
    cout << ans;
    return 0;
}
