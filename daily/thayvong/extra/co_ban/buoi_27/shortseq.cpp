#include <bits/stdc++.h>
#define simon "shortseq"
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
ll k;

int main(){
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    FASTio
    cin >> n >> k;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    int l=1;
    ll s=0;
    int ans=INT_MAX;
    for (int r=1; r<=n; r++){
        s+=a[r];
        while ( s >= k ){
            if ( s == k ) ans=min(ans, r-l+1);
            s-=a[l];
            l++;
        }
    }
    if ( ans==INT_MAX  ) cout << 0;
    else cout << ans;
    return 0;
}
