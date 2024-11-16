#include <bits/stdc++.h>
using namespace std;

int n, a[1000001], dem[1000001];

int main(){
    freopen("maxgcd.inp","r",stdin);
    freopen("maxgcd.out","w",stdout);
    cin >> n;
    if ( n <= 1000 ){
        for (int i=1; i<=n; i++)
            cin >> a[i];
        int ans=INT_MIN;
        for (int i=1; i<n; i++)
            for (int j=i+1; j<=n; j++)
                ans= max(ans,__gcd(a[i],a[j]));
        cout << ans;
        return 0;
    }
    else{
    for (int i=1; i<=n; i++){
        cin >> a[i];
        dem[a[i]]++;
    }
    int ans=1;
    for (int d=2; d<=1000000; d++){
        int t=1, x=0;
        while ( t*d <= 1000000 ){
            x+=dem[t*d];
            t++;
        }
        if ( x >= 2 ) ans=d;
    }
    cout << ans;
    return 0;
    }
}
