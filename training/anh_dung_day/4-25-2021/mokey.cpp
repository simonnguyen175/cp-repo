#include<bits/stdc++.h>
#define ll long long
#define simon "monkey"
using namespace std;
const int N=1e6+5;

ll t, m, n;
ll a[N], b[N], c[N], d[N], res;

int main(){
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".inp", "w", stdout);
    }
    /// input
    cin >> t;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i] >> b[i];
    cin >> m;
    for(int i=1; i<=m; i++)
    cin >> c[i] >> d[i];

    /// bin search
    ll l=0, r=t;
    while(l<=r){
        ll mid=(l+r)/2, x=0, y=0;
        for(int i=1; i<=n; i++)
            x +=(mid-a[i])/b[i] + 1 ;
        for(int i=1; i<=m;i++)
            y +=(t-mid-c[i])/d[i] + 1 ;
        if ( x == y ){
            res=mid;
            break;
        }
        if ( x > y ) r=mid-1;
        if ( x < y ) l=mid+1;
    }
    cout << res;
    return 0;
}
