#include<bits/stdc++.h>
#define simon "SUBSTR"
#define pi pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

int n;
string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> s;
    s += '@';
    n = s.size();
    vector<int> a(n);
    vector<pi> key(n), nkey(n);
    iota(a.begin(), a.end(), 0);
    for (int i = 0; i < n; i ++)
        key[i].fi = s[i];

    int d = 1;
    while ( true ){
        for (int i = 0; i < n; i ++)
            key[i].se = key[(i+d)%n].fi;
        sort(a.begin(), a.end(), [&](int i, int j){
            return key[i] < key[j];
        });
        int Rank = 0;
        for (int i = 0; i < n; i ++){
            if ( i && key[a[i]] != key[a[i-1]] )
                Rank ++;
            nkey[a[i]].fi = Rank;
        }
        swap(key, nkey);
        if ( d >= n ) break;
        d *= 2;
    }


    vector<int> Rank(n), p(n);
    for (int i = 0; i < n; i ++)
        Rank[a[i]] = i;

    p[0] = 0;
    int q = 0;

    for (int i = 0; i < n-1; i ++){
        int j = a[Rank[i]-1];
        while ( s[i+q] == s[j+q] ) q ++;
        p[Rank[i]] = q;
        if ( q ) q --;
    }

    ll ans = 1LL * n * (n-1) / 2;

    for (int i = 0; i < n; i ++) ans -= p[i];
    cout << ans;

    return 0;
}
