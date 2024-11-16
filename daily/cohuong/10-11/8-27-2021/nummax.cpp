#include<bits/stdc++.h>
#define ll long long
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define simon "nummax"
using namespace std;
const int N = 1e5 + 5;

int n, b, a[N];
ll ans = 0;

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> n >> b;
    for (int i=1; i<=n; i++)
        cin >> a[i];

    int l=0, r=0;

    for (int i=1; i<=n; i++){
        if ( a[i] > b ){
            l=i;
            r=i;
        }
        if ( a[i] == b ) r = i;
        cout << l << ' ' << r << '\n';
        ans += r - l;
    }

    cout << ans;

    return 0;
}
