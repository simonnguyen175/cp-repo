
#include <bits/stdc++.h>
using namespace std;
#define nmax 30001

int n, a[nmax], f[nmax];
int m, b[nmax];

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
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >>  a[i];


    for (int i=1; i<=n; i++){
        int temp = tknp( b, 1, m, a[i] );
        f[i]= temp + 1;
        m = max(m, f[i]);
        b[f[i]]=a[i];
    }

    cout << m ;
    return 0;
}
