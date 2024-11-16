#include <bits/stdc++.h>
#define simon "ABC"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1e5+1;

int n;
string s;
long long a[N], ab[N], c[N], bc[N];
long long ans=0;

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> s;

    for (int i = 0; i <= n - 1; i ++){
        if ( s[i] == 'A' ) a[i] = a[i-1] + 1; else a[i] = a[i-1];
        if ( s[i] == 'B' ) ab[i] = ab[i-1] + a[i-1]; else ab[i] = ab[i-1];
        if ( s[i] == 'C' ) ans += ab[i];
    }

    for (int i = n - 1; i >= 0; i --){
        if ( s[i] == 'C' ) c[i] = c[i+1] + 1; else c[i] = c[i+1];
        if ( s[i] == 'B' ) bc[i] = bc[i+1] + c[i+1]; else bc[i] = bc[i+1];
    }

    long long tmp = max(ab[n-1], bc[0]);
    for (int i = 1; i <= n - 1; i ++)
        tmp = max(tmp, c[i] * a[i]);

    cout << ans + tmp;

    return 0;
}
