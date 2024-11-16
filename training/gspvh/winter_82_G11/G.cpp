#include<bits/stdc++.h>
using namespace std;

string a, b;
map<string, int> d, vis;

void go(string x){
    if ( vis[x] ) return;
    vis[x] = 1;

    if ( x[x.size()-1] == 'A' ){
        string y = x;
        y.erase(y.size()-1, 1);
        go(y);
        d[x] |= d[y];
    }

    if ( x[0] == 'B' ){
        string y = x;
        reverse(y.begin(), y.end());
        y.erase(y.size()-1, 1);
        go(y);
        d[x] |= d[y];
    }
}

void solve(){
    d.clear();
    vis.clear();
    vis[a] = d[a] = 1;
    go(b);
    if ( d[b] ) cout << "Yes\n";
    else cout << "No\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("abba.inp", "r", stdin);
    freopen("abba.out", "w", stdout);

    while ( cin >> a >> b )
        solve();

    return 0;
}
