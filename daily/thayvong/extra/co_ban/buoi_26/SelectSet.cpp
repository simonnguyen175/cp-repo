#include <bits/stdc++.h>
#define simon "SelectSet"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define cc pair<char, char>
using namespace std;
const int N=1e5+1;
const ll oo=1e18;

int n, m, a[N], d[N];

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        a[i]%=m;
    }
    sort(a+1, a+1+n);
    memset(d, 0, sizeof d);
    for (int i=1; i<=n; i++)
        d[a[i]]++;
    int ans=0;
    for (int i=1; i<=(m-1)/2; i++)
        ans+=max(d[i], d[m-i]);
    if ( m % 2 == 0 && d[m/2] > 0 ) ans++;
    if ( d[0] > 0 ) ans++;
    cout << ans;
    return 0;
}
