#include <bits/stdc++.h>
#define simon "dovat"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define cc pair<char, char>
using namespace std;
const int N=1e5+1;
const ll oo=1e18;

int n, m, a[N];

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    sort(a+1, a+1+n);
    int s=0;
    int res=0, dc=0;
    for (int i=1; i<=n; i++){
        //cout << s << ' '<<dc <<' '<<res<<'\n';
        if ( s + a[i] <= m ){
            if ( a[i] % 2 == 0  && dc == 1 ) continue;
            s+=a[i]; res++;
            if ( a[i] % 2 == 0 ) dc++;
        }
    }
    cout << res;
    return 0;
}
