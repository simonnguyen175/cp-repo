#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        cin >> u >> v >> x >> y;
        row.pb(u), row.pb(x);
        col.pb(x), col.pb(y);
    }

    sort(row.begin(), row.end());
    sort(col.begin(), col.end());
}
