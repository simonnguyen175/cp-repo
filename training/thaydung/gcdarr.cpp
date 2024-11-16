#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll a[105];
map<ll, int> d;

void solve(){
    cin >> n;
    d.clear();
    bool ck = 1;
    int odd = 0, even = 0;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        if ( d[a[i]] ) ck = 0;
        if ( a[i] % 2 ) odd ++;
        else even ++;
        d[a[i]] = 1;
    }

    if ( !ck | ( even >= 2 && odd >= 2 ) ) return cout << "NO\n", void();

    for (ll p = 1; p <= 100; p ++){
        bool ck = 1;
        for (int i = 1; i <= n; i ++)
        for (int j = i + 1; j <= n; j ++)
            if ( __gcd(a[i] + p, a[j] + p) > 1 )
                { ck = 0; break; }
        if ( ck ) return cout << "YES\n", void();
    }

    cout << "NO\n";
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
