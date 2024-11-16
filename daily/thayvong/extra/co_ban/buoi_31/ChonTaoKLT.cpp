#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define simon "ChonTaoKLT"
using namespace std;
const int N = 1e5 + 5;

long long n, a[N], d[3], ans;

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        d[a[i] % 3] ++;
    }

    if ( d[1] <= d[2] ) ans = max({2*d[1] + d[0] + ( ( d[2] - d[1] ) / 3 ) * 3, ( d[1] / 3 ) * 3, ( d[2] / 3 ) * 3, d[0] + ( d[1] / 3 ) * 3 + ( d[2] / 3 ) * 3});
    else ans = max({2*d[2] + d[0] + ( ( d[1] - d[2] )/ 3 ) * 3, ( d[1] / 3 ) * 3, ( d[2] / 3 ) * 3, d[0] + ( d[1] / 3 ) * 3 + ( d[2] / 3 ) * 3});

    cout << ans;

    return 0;
}
