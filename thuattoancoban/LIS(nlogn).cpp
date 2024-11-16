#include <bits/stdc++.h>
#define simon "dayso"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1e6+1;

int n, a[N], f[N];
int m, b[N];

int tknp(int b[], int l, int r, int x){
    int d=l, c=r, mid, res=0;
    while ( d <= c ){
        mid = (d+c)/2;
        if ( b[mid] < x ){
            res = mid;
            d = mid + 1;
        }
        else
            c = mid - 1;
    }
    return res;
}

int main(){
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];

    for (int i=1; i<=n; i++){
        int temp = tknp( b, 1, m, a[i] );
        f[i]= temp + 1;
        m = max(m, f[i]);
        b[f[i]] = a[i];
    }
    cout << m;
    return 0;
}
