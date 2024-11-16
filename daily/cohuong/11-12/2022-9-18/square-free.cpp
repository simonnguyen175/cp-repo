#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;

int l, r;
int f[N];

bool cp(int x){
    int y = sqrt(x);
    return y * y == x;
}

namespace sub2{
    bool check(int x){
        if ( x != 1 && cp(x) ) return 0;
        for (int i = 2; i <= sqrt(x); i ++) if ( x % i == 0 )
            if ( cp(i) || cp(x/i) ) return 0;
        return 1;
    }

    void solve(){
        int ans = 0;
        for (int i = l; i <= r; i ++)
            ans += check(i);
        cout << ans << '\n';
    }
}

namespace sub3{
    void solve(){
        int ans = 0;
        for (int i = l; i <= r; i ++)
            ans += !f[i];
        cout << ans << '\n';
    }
}

void solve(){
    cin >> l >> r;
    if ( r >= N ) sub2::solve();
    else sub3::solve();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("square-free.inp", "r", stdin);
    freopen("square-free.out", "w", stdout);

    for (int i = 2; i < N; i ++) if ( cp(i) )
    for (int j = i; j < N; j += i) f[j] ++;

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
