#include <bits/stdc++.h>
using namespace std;

int a[10001], n ;

int main(){
    cin >> n ;
    int DemDuong = 0;
    for (int i=1; i<=n; i++){
        cin >> a[i] ;
        if ( a[i] > 0 ) DemDuong++;
    }
    sort (a+1,a+1+n);
    if ( DemDuong >= 3 ) cout << max (a[n]*a[n-1]*a[n-2],a[n]*a[1]*a[2]);
    if ( DemDuong == 2 ){
        int res = max (a[n]*a[n-1]*a[n-2],a[n-2]*a[n-1]*a[n-3]);
        cout << res ;
    }
    if ( DemDuong == 1) cout << a[n]*a[1]*a[2];
    if ( DemDuong == 0){
        if (a[n] == 0) cout << 0 ;
        else cout << a[n]*a[n-1]*a[n-2];
    }
    return 0;
}
