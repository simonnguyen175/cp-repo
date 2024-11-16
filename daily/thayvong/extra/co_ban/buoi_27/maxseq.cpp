#include <bits/stdc++.h>
#define simon "maxseq"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define cc pair<char, char>
using namespace std;
const int N=1e6+5;
const ll oo=1e15;
const int MOD=123456789;

int n, a[N];

int main(){
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    FASTio
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    ll s=0, nn=0, ans=LLONG_MIN;
    for (int i=1; i<=n; i++){
        s+=a[i];
        ans=max(ans, s-nn);
        nn=min(nn, s);
    }
    cout << ans;
    return 0;
}
