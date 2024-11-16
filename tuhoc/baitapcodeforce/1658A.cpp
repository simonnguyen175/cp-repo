#include<bits/stdc++.h>
using namespace std;

int t, n;
string s;

void solve(){
    cin >> n >> s;
    s = ' ' + s;

    int cnt = 0, ans = 0;
    int pos;

    for (int i = 1; i <= n; i ++) if ( s[i] == '0' ) { pos = i; break; }

    for (int i = pos + 1; i <= n; i ++){
        if ( s[i] == '0' ){
            ans += max(0, 2-cnt);
            cnt = 0;
        }
        else cnt ++;
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> t;
    while ( t -- ) solve();
    return 0;
}
