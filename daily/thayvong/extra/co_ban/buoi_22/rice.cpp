#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int R=1e5+1;

int r, l, x[R], ans=0;
ll b, s[R];

ll cost(int d, int c){
    int pos = (d+c)/2;
    return (pos-d)*x[pos]-(s[pos-1]-s[d-1])+s[c]-s[pos]-(c-pos)*x[pos];
}

int tknp(int l, int r){
    int d=l, c=r, res;
    while ( d <= c ){
        int mid=(d+c)/2;
        if ( cost(l, mid) <= b ){
            d=mid+1;
            res=mid;
        }
        else c=mid-1;
    }
    return res;
}

int main(){
    freopen("rice.inp","r",stdin);
    freopen("rice.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> r >> l >> b;
    for (int i=1; i<=r; ++i) cin >> x[i];
    for (int i=1; i<=r; ++i)
        s[i]=s[i-1]+x[i];
    for (int i=1; i<=r; ++i){
        int pos = tknp(i, r);
        ans = max(ans, pos-i+1);
    }
    cout << ans;
    return 0;
}
