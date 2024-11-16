#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;

int n;
string org, fin, cur, nxt;
unordered_map<string, int> d, h;
queue<string> q;

void solve(){
    cin >> n;
    org = fin = "";
    for (int i = 1; i <= n; i ++){
        int x;
        cin >> x;
        org += (char) ('a' + x - 1);
        fin += (char) ('a' + i - 1);
    }

    if ( org == fin ) { cout << 0 << '\n'; return; }

    d.clear();
    while ( q.size() ) q.pop();
    q.push(org);
    d[org] = 0;
    while ( q.size() ){
        cur = q.front();
        q.pop();

        if ( cur == fin ) { cout << d[cur] << '\n'; return; }

        if ( d[cur] == 2 ) break;

        for (int i = 0; i < n; i ++)
        for (int j = i; j < n; j ++){
            for (int p = 0; p < i; p ++){
                nxt = "";
                nxt += cur.substr(0, p);
                nxt += cur.substr(i, j-i+1);
                nxt += cur.substr(p, i-p);
                nxt += cur.substr(j+1, n-j-1);

                if ( nxt != org && !d[nxt] ){
                    d[nxt] = d[cur] + 1;
                    q.push(nxt);
                }
            }

            for (int p = j+1; p < n; p ++){
                nxt = "";
                nxt += cur.substr(0, i);
                nxt += cur.substr(j+1, p-j);
                nxt += cur.substr(i, j-i+1);
                nxt += cur.substr(p+1, n-p-1);

                if ( nxt != org && !d[nxt] ){
                    d[nxt] = d[cur] + 1;
                    q.push(nxt);
                }
            }
         }
    }

    h.clear();
    while ( q.size() ) q.pop();
    q.push(fin);
    h[fin] = 0;
    while ( q.size() ){
        cur = q.front();
        q.pop();

        if ( h[cur] == 2 ) break;

        for (int i = 0; i < n; i ++)
        for (int j = i; j < n; j ++){
            for (int p = 0; p < i; p ++){
                nxt = "";
                nxt += cur.substr(0, p);
                nxt += cur.substr(i, j-i+1);
                nxt += cur.substr(p, i-p);
                nxt += cur.substr(j+1, n-j-1);

                if ( nxt != fin && !h[nxt] ){
                    h[nxt] = h[cur] + 1;
                    q.push(nxt);
                }
            }

            for (int p = j+1; p < n; p ++){
                nxt = "";
                nxt += cur.substr(0, i);
                nxt += cur.substr(j+1, p-j);
                nxt += cur.substr(i, j-i+1);
                nxt += cur.substr(p+1, n-p-1);

                if ( nxt != fin && !h[nxt] ){
                    h[nxt] = h[cur] + 1;
                    q.push(nxt);
                }
            }
         }
    }

    int ans = -1;
    for (auto it : d){
        if ( h.find(it.fi) != h.end() ){
            if ( ans == -1 ) ans = it.se + h[it.fi];
            else ans = min(ans, it.se + h[it.fi]);
        }
    }

    if ( ans == -1 ) cout << "5 or more\n";
    else cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("kittens.inp", "r", stdin);
    freopen("kittens.out", "w", stdout);

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
