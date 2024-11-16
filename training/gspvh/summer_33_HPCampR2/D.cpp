#include<bits/stdc++.h>
#define simon "minimum"
#define ll long long
using namespace std;
const int N = 5e6 + 5;
const ll oo = 1e18;

int n, x, y;
int a[N];
ll s[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> x >> y;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], s[i] = s[i-1] + a[i];
    s[n+1] = oo;

    ll ans = -oo/2;
    int l, r;
    int pos = n+1, pre = 0;
    for (int i = 1; i <= n; i ++)
        if ( a[i] < x )
            pos = n+1, pre = i;
        else if ( a[i] <= y ){
            for (int j = pre; j < i; j ++)
                if ( s[pos] > s[j] ) pos = j;
            if ( ans < s[i] - s[pos] )
                ans = s[i] - s[pos], l = pos + 1, r = i;
            pre = i;
        }
        else if ( ans < s[i] - s[pos] )
            ans = s[i] - s[pos], l = pos + 1, r = i;

    cout << ans << '\n' << l << ' ' << r << '\n';

    return 0;
}
