#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e18;

int n, nb, nc;
ll a[N], b[N], c[N], sb[N], sc[N], ans = oo, pre;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("teleport.inp", "r") ){
        freopen("teleport.inp", "r", stdin);
        freopen("teleport.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        if ( a[i] < 0 ) b[++nb] = -a[i];
        else c[++nc] = a[i];
    }

    sort(b + 1, b + 1 + nb);
    sort(c + 1, c + 1 + nc);

    for (int i = 1; i <= nb; i ++) sb[i] = sb[i-1] + b[i];
    for (int i = 1; i <= nc; i ++) sc[i] = sc[i-1] + c[i];

    ans = sb[nb] + sc[nc];

   //cout << ans << '\n';

    pre = sc[nc];
    for (int i = 1; i <= nb; i ++){
        int med = (nb + i) / 2;
        ll s1 = sb[nb] - sb[med] - ( nb - med ) * b[med];
        ll s2 = (med - i + 1) * b[med] - ( sb[med] - sb[i-1] );
        //cout << med << ' ' << s1 << ' ' << s2 << '\n';
        ans = min(ans, s1 + s2 + pre);
        pre += b[i];
    }

    //cout << ans << '\n';

    pre = sb[nb];
    for (int i = 1; i <= nc; i ++){
        int med = (nc + i) / 2;
        ll s1 = sc[nc] - sc[med] - ( nc - med ) * c[med];
        ll s2 = (med - i + 1) * c[med] - ( sc[med] - sc[i-1] );
        ans = min(ans, s1 + s2 + pre);
        pre += c[i];
    }

    cout << ans;

    return 0;
}
