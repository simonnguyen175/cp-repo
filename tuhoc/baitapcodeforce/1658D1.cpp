#include<bits/stdc++.h>
#define BIT(x,k) ((x>>k)&1)
using namespace std;

int t, l, r;
int a[1000000];

void solve(){
    cin >> l >> r;
    for (int i = 0; i <= r; i ++) cin >> a[i];

    int ans = 0;
    for (int i = 0; i <= 18; i ++){
        int cnt0 = 0, cnt1 = 0;
        for (int j = 0; j <= r; j ++){
            cnt0 += !BIT(a[j], i);
            cnt1 += BIT(a[j], i);
        }
        ans += ( cnt0 < cnt1 ) * ( 1 << i );
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
