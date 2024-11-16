#include<bits/stdc++.h>
#define simon "seqbalance"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e6 + 5;

int n, a[N];
long long f[N];

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    f[1] = 0;
    f[2] = abs(a[2] - a[1]);

    for (int i = 3; i <= n; i ++){
        if ( a[i] >= a[i-1] && a[i-1] >= a[i-2] ) f[i] = f[i-1] + a[i] - a[i-1];
        if ( a[i] <= a[i-1] && a[i-1] <= a[i-2] ) f[i] = f[i-1] + a[i-1] - a[i];
        if ( a[i] >= a[i-1] && a[i-1] <= a[i-2] ) f[i] = max(f[i-2] + a[i] - a[i-1], f[i-1]);
        if ( a[i] <= a[i-1] && a[i-1] >= a[i-2] ) f[i] = max(f[i-2] + a[i-1] - a[i], f[i-1]);
    }

    cout << f[n];
    return 0;
}
