#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=1e5+1;

int n, f[N];
pair<int, int> a[N];

int tknp(int l, int r, int key){
    int d=l, c=r, mid, res = 0;
    while ( d <= c ){
        mid=(d+c)/2 ;
        if ( a[mid].fi < key ){
            res=mid;
            d=mid+1;
        }
        else c=mid-1;
    }
    return res;
}

int main(){
    freopen("NoIntersect.inp","r",stdin);
    freopen("NoIntersect.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i].se >> a[i].fi;
    sort(a+1, a+1+n);
    f[1]=1;
    for (int i=2; i<=n; i++){
        f[i]=f[i-1];
        int j=tknp(1, i-1, a[i].se);
        if ( j == 0 ) continue;
        if ( a[j].fi < a[i].se )
            f[i]=max(f[i-1], 1+f[j]);
    }
    cout << f[n];
    return 0;
}
