#include<bits/stdc++.h>
#define simon "BoundSeq"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fi first
#define se second
using namespace std;
const int N = 5e5 + 5;

int n;
int a[N], Log[N];
pair<int, int> st[N][30];

int getmin(int l, int r){
    int j = Log[r-l+1];
    return min(st[l][j].fi, st[r-(1<<j)+1][j].fi);
}

int getmax(int l, int r){
    int j = Log[r-l+1];
    return max(st[l][j].se, st[r-(1<<j)+1][j].se);
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    Log[0] = 0;
    for (int i = 2; i <= n; i ++)
        Log[i] = Log[i/2] + 1;

    for (int i = 1; i <= n; i ++){
        st[i][0].fi = a[i];
        st[i][0].se = a[i];
    }

    for (int j = 1; j <= Log[n]; j ++)
        for (int i = 1; i + ( 1 << j ) - 1 <= n; i ++){
            st[i][j].fi = min(st[i][j-1].fi, st[i+(1<<(j-1))][j-1].fi);
            st[i][j].se = max(st[i][j-1].se, st[i+(1<<(j-1))][j-1].se);
        }

    int ans = 0;



    for (int i = 1; i <= n; i ++){
        int lo, hi, r;

        // find minbound
        lo = i; hi = n;

        while ( lo <= hi ){
            int mid = ( lo + hi ) / 2;
            if ( getmin(i, mid) == a[i] ){
                r = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }

        // find maxbound
        int mx = getmax(i, r);
        lo = i; hi = r;
        int res;

        while ( lo <= hi ){
            int mid = ( lo + hi ) / 2;
            if ( a[mid] == mx ){
                res = mid;
                lo = mid + 1;
                continue;
            }

            if ( getmax(mid, hi) == mx ) lo = mid + 1;
            else hi = mid - 1;
        }

        ans = max(ans, res - i + 1);
    }

    if ( ans == 1 ) cout << -1;
    else cout << ans;

    return 0;
}

