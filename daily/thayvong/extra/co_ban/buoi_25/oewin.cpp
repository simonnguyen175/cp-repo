#include <bits/stdc++.h>
#define simon "oewin"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
using namespace std;
const int N=1e6+1;
const int oo=1e18;

int n, k;
int a[N], odd=0, even=0;
ll ans=INT_MAX, s;

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> n >> k;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=k; i++){
        s+=a[i];
        if ( abs(a[i]) % 2 == 0 ) even++;
        else odd++;
    }
    if ( odd > 0 && even > 0 ) ans=min(ans, s);

    for (int i=k+1; i<=n; i++){
        s=s-a[i-k]+a[i];
        if ( abs(a[i-k]) % 2 == 0 ) even--;
        else odd--;
        if ( abs(a[i]) % 2 == 0 ) even++;
        else odd++;
        if ( odd > 0 && even > 0 ) ans=min(ans, s);
    }
    cout << ans;
    return 0;
}
