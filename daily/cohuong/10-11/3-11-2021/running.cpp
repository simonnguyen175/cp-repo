#include <bits/stdc++.h>
using namespace std;
const int N=1e3+1;

int n, a[N], ans=0;

int tknp(int l, int r, int key, bool x){
    int d=l, c=r, res=0;
    if ( x ){
        while ( d <= c ){
            int mid=(d+c)/2;
            if ( a[mid] >= key ){
                res=mid;
                c=mid-1;
            }
            else d=mid+1;
        }
        return res;
    }
    else{
        while ( d <= c ){
            int mid=(d+c)/2;
            if ( a[mid] <= key ){
                res=mid;
                d=mid+1;
            }
            else c=mid-1;
        }
        return res;
    }
}

int main(){
    freopen("RUNNING.inp","r",stdin);
    freopen("RUNNING.out","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    sort(a+1, a+1+n);
    for (int i=1; i<=n-2; i++)
        for (int j=i+1; j<=n-1; j++){
            int x=a[i], y=a[j];
            int zd=tknp(j+1, n, 2*y-x, 1);
            int zc=tknp(j+1, n, y+2*(y-x), 0);
            if ( zd == 0 || zc == 0 ) continue;
            ans += zc-zd+1;
        }
    cout << ans;
    return 0;
}
