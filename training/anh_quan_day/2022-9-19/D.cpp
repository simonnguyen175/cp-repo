#include<bits/stdc++.h>
using namespace std;

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> q;
    while ( q -- )
        solve();

    return 0;
}
