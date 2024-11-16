#include<bits/stdc++.h>
#define ll long long
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define simon "DHSEQGAME"
using namespace std;
const int N=1e3+5;

int n, d, a[N];
ll cost=LLONG_MAX;

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> n >> d;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=n; i++){
        int mid=a[i];
        int l=a[i]-(i-1)*d;
        int r=a[i]+(n-i)*d;
        ll tmp=0;
        for (int j=1; j<i; j++){
            tmp+=abs(a[j]-l);
            l+=d;
        }
        for (int j=n; j>i; j--){
            tmp+=abs(a[j]-r);
            r-=d;
        }
        cost=min(tmp, cost);
    }
    cout << cost;
    return 0;
}
