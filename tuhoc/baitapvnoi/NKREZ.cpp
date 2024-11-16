#include <bits/stdc++.h>
using namespace std;

struct offer{
    int p;
    int k;
};

int n, f[100001];
offer a[100001];

bool compair(offer a, offer b){
    if ( a.k < b.k ) return true;
    else return false;
}

int tknp(int l, int r, int key){
    int d=l, c=r, mid, res;
    while ( d <= c ){
        mid=(d+c)/2 ;
        if ( a[mid].k <= key ){
            res=mid;
            d=mid+1;
        }
        else
            c=mid-1;
    }
    return res;
}

int main(){
    // input & setup
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i].p >> a[i].k;
    sort(a+1,a+1+n, compair);
    // solve
    f[0]=0;
    for (int i=1; i<=n; i++){
        f[i]=max(a[i].k-a[i].p, f[i-1]);
        int j=tknp(1,i-1,a[i].p);
        if ( a[j].k <= a[i].p )
            f[i]=max(f[i], a[i].k-a[i].p+f[j]);
    }
    cout << f[n];
    return 0;
}
