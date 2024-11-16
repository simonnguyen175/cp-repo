#include<bits/stdc++.h>
#define BIT(x,k) ((x>>k)&1)
using namespace std;

int t, n, A, O, X, cnt[35];

void solve(){
    cin >> n >> A >> O >> X;

    if ( (A&O) != A ) { cout << -1 << '\n'; return; }

    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i <= 30; i ++)
        if ( BIT(A, i) ) cnt[i] += n;

    for (int i = 0; i <= 30; i ++)
        if ( BIT(O, i) && !cnt[i] ) cnt[i] ++;

    for (int i = 0; i <= 30; i ++)
        if ( BIT(X, i) && cnt[i]%2 == 0 ){
            cout << -1 << '\n';
            return;
        }

    for (int i = 1; i <= n - 1; i ++)
        cout << A << ' ';
    cout << O << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> t;
    while ( t -- ) solve();
    return 0;
}
