#include<bits/stdc++.h>
#define pb push_back
#define int long long
#define BIT(x,k) ((x>>k)&1)
using namespace std;

int n, np, test;
vector<int> pri;
int c[2000];

int cdiv(int a, int b, int c){
    return b/c - (a-1)/c;
}

void solve(){
    int a, b;
    cin >> a >> b;
    int ans = b-a+1;
    for (int i = 1; i < (1<<np); i ++){
        int cnt = cdiv(a, b, c[i]);
        if ( __builtin_popcount(i) % 2 ) ans -= cnt;
        else ans += cnt;
    }
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> test;
    for (int i = 2; i * i <= n; i ++) if ( n % i == 0 ){
        pri.pb(i);
        while ( n % i == 0 ) n /= i;
    }
    if ( n != 1 ) pri.pb(n);
    np = pri.size();

    for (int i = 0; i < (1<<np); i ++){
        c[i] = 1;
        for (int j = 0; j < np; j ++) if ( BIT(i, j) )
            c[i] *= pri[j];
    }

    while ( test -- )
        solve();

    return 0;
}
