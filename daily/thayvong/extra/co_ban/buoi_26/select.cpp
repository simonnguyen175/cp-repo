#include <bits/stdc++.h>
#define simon "select"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define cc pair<char, char>
using namespace std;
const int N=1e5+1;
const ll oo=1e18;

int n, dp[N];
pair<int, int> a[N];

int tknp(int l, int r, int key){
    int d=l, c=r, res=0;
    while ( d <= c ){
        int mid=(d+c)/2;
        if ( a[mid].fi <= key ){
            res=mid;
            d=mid+1;
        }
        else c=mid-1;
    }
    return res;
}

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i].se >> a[i].fi;
    sort(a+1, a+1+n);
    memset(dp, 0, sizeof dp);
    int ans=0;
    for (int i=1; i<=n; i++){
        int pos=tknp(0, i-1, a[i].se);
        dp[i]=max(dp[i-1], dp[pos]+1);
        ans=max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}
