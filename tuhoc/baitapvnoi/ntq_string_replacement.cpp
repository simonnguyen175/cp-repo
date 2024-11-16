#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int m;
string a, b;
map<string, int> d;
map<string, vector<string>> g;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> a >> b;
    cin >> m;
    for (int i = 1; i <= m; i ++){
        string u, v;
        cin >> u >> v;
        g[u].pb(v);
    }

//    for (auto it : g){
//        cout << it.first << " : ";
//        for (auto x : it.second)
//            cout << x << ' ';
//        cout << '\n';
//    }


    d[a] = 1;
    queue<string> q;
    q.push(a);
    while ( q.size() ){
        string u = q.front();
        int du = d[u];
        q.pop();

        string t = "";
        string v = u;
        int n = u.size();
        for (int i = 1; i <= n; i ++){
            t += u[n-i];
//            cout << t << ' ';
            if ( g.find(t) != g.end() )
            for (auto k : g[t]){
                v = u;
//                cout << "-> " << k << '\n';
                for (int j = 1; j <= i; j ++)
                    v[n-j] = k[i-j];
//                cout << "=> " << v << '\n';
                if ( d.find(v) == d.end() ){
                    d[v] = du + 1;
                    q.push(v);
                }
            }
//            cout << '\n';
        }
    }

    if ( !d[b] ) cout << -1;
    else cout << d[b] - 1;

    return 0;
}
