#include<bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;

int t, n, ans;
int a[N];

void xuli(int x){
    int gcd2 = 0;
    for (int i = 1; i <= n; i ++) if ( a[i] % x )
        gcd2 = __gcd(a[i], gcd2);

    ans = max(ans, min(x, gcd2));
}

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];

    sort(a + 1, a + 1 + n);

    vector<int> dcont;
    for (int i = 1; i * i <= a[1]; i ++)
        if ( a[1] % i == 0 )
            dcont.push_back(i), dcont.push_back(a[1]/i);

    ans = 1;

    for (int d : dcont) if ( d != 1 ) xuli(d);

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> t;
    while ( t -- ) solve();
    return 0;
}
