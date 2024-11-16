#include<bits/stdc++.h>
#define simon "landing"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e5+5;

int n, k, x;
int t[5];
pair<int, int> a[N];

int solve(int x){
    int t[5], ans = 0, ii, e;
    for (int i=1; i<=k; i++)
        t[i] = -x;
    for (int i = 1; i<= n; i++){
        ii = 1;
        for (int j=1; j<=k; j++)
            if ( t[ii] > t[j] )
                ii = j;

        e = t[ii] + x;

        if ( a[i].second < e ) continue;
            ans++;
        t[ii] = max(e, a[i].first);
    }
    return ans;
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> n >> k >> x;
    int mx = 0;
    for (int i=1; i<=n; i++){
        cin >> a[i].first >> a[i].second;
        mx = max(mx, a[i].second);
    }
    sort(a+1, a+1+n);

    int ans = solve(x);
    int l = x, r = mx, e = x, u;
    while ( l <= r ){
        int mid = ( l + r ) / 2;
        u = solve(mid);
        if ( u == ans ){
            e = mid;
            l = mid + 1;
        }
        else r = mid -1;
    }

    if ( ans <= k ) cout << ans <<' '<<-1;
    else cout << ans <<' '<<e;
    return 0;
}
