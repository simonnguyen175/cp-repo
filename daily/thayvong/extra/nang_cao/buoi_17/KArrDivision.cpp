#include <bits/stdc++.h>
using namespace std;
const int N=2e5+1;

int n, k, a[N], MAX;
long long res;

bool check(long long x){
    int sodoan=0;
    long long tmp=0;

    for (int i=1; i<=n; i++){
        if ( a[i] > x ) return false;
        if ( tmp + a[i] > x ){
            tmp=a[i];
            sodoan++;
        }
        else tmp+=a[i];
    }

    if ( tmp > x ) return false;
    else sodoan++;
    if ( sodoan > k ) return false;
    else return true;
}

int main(){
    freopen("KArrDivision.inp","r",stdin);
    freopen("KArrDivision.out","w",stdout);
    ios::sync_with_stdio(0);
		cin.tie(0);
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        int MAX=max(MAX, a[i]);
    }
    long long d=1, c=1e14;
    while ( d <= c ){
        long long mid=(d+c)/2;
        if ( check(mid) && MAX <= mid ){
            c=mid-1;
            res=mid;
        }
        else d=mid+1;
    }
    cout << res;
    return 0;
}
