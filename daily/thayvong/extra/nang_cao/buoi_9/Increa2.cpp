#include <bits/stdc++.h>
using namespace std;

int n, a[1000001];

int tknp(long long x, int l, int r){
    int d=l, c=r, mid, res=0;
    while ( d <= c ){
        mid = ( d + c )/2;
        if ( a[mid] >= x ){
            c=mid-1;
            res=mid;
        }
        else d=mid+1;
    }
    return res;
}

int main() {
    freopen("Increa2.inp","r",stdin);
    freopen("Increa2.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    int l=n, r=1;
    for (int i=1; i<=n-1; i++)
        if (a[i] > a[i+1]){
            l=i;
            break;
        }
    for (int i=n; i>=2; i--)
        if (a[i] < a[i-1]){
            r=i;
            break;
        }
    if ( l >= n-1){cout <<n-l; return 0;}
    if ( r <= 2 ){cout << r-1; return 0;}
    int ans=n-1;
    for (int i=1; i <= l; i++){
        int k = tknp(a[i],r,n);
        if ( k == 0 )
            ans= min(ans, n-i);
        else
            ans= min(ans, k-i-1);
    }
    cout << ans;
    return 0;
}
