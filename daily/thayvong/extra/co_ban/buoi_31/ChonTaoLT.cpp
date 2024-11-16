#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define simon "ChonTaoLT"
using namespace std;
const int N = 1e5 + 5;

int n, a[N], p[5], ans;

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    long long s = 0;

    for (int i = 1; i <= n; i ++){
        s = ( s + a[i] ) % 3;
        if ( s == 0 ) {ans = i; continue;}
        if ( p[s] > 0 )
            ans = max(ans, i - p[s]);
        else p[s] = i;
    }
    cout << ans;
    return 0;
}
