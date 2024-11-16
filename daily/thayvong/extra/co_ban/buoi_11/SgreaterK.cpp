#include <bits/stdc++.h>
using namespace std;

long long n, k ;
long long a[500001],s[500001];

long long tknp(long long t,long long  i){
    long long l=1, r=i, res, mid;
    while ( l <= r ){
        mid = (l+r)/2;
        if ( s[mid] <= t ){
            res = mid;
            l=mid+1;
        }
        else  r=mid-1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    freopen("SgreaterK.inp","r",stdin);
    freopen("SgreaterK.out","w",stdout);
    cin >> n >> k;
    long long ans=0 ;
    for (long long i=1; i<=n; i++)
        cin >> a[i];
    s[0]=0;
    for (long long i=1; i<=n; i++)
        s[i]=s[i-1]+a[i];
    for (long long i=1; i<=n; i++){
        if (s[i]>=k) ans++ ;
        int p = tknp(s[i]-k,i-1);
        if ( p > 0 ) ans += p ;
    }
    cout << ans ;
    return 0;
}
