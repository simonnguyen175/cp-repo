#include<bits/stdc++.h>
#define simon "las1"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 1e6 + 5;

int n, d, ans;
ll a[N];
map<ll, int> b;

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> n >> d;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 1; i <= n; i ++){
        if ( b[a[i]-d] > 0 )
            b[a[i]] = b[a[i]-d] + 1;
        else
            b[a[i]] = 1;
        ans = max(ans, b[a[i]]);
    }

    cout << ans;

    return 0;
}
