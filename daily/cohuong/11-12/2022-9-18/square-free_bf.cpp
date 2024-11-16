#include<bits/stdc++.h>
using namespace std;

int test, l, r;

bool cp(int x){
    int y = sqrt(x);
    return y * y == x;
}

bool check(int x){
    if ( x != 1 && cp(x) ) return 0;
    for (int i = 2; i <= sqrt(x); i ++) if ( x % i == 0 )
        if ( cp(i) || cp(x/i) ) return 0;
    return 1;
}

void solve(){
    cin >> l >> r;
    int ans = 0;
    for (int i = l; i <= r; i ++)
        ans += check(i);
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int test;
    cin >> test;
    while ( test -- )
        solve();
    return 0;
}
