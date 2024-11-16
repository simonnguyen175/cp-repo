#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[100001], d[100001];

int tknp(int x, int l, int r){
    int d=l, c=r, mid;
    while ( d <= c ){
        mid = ( d + c )/2;
        if (a[mid]==x) return mid;
        else
        	if (a[mid]<x) d=mid+1;
        		else c=mid-1;
    }
    return 0;
}

int main(){
    cin >> n >> k;
    int ans ;
    for (int i=1; i<=n; i++)
    	cin >> a[i];

    for (int i=1; i<=n; i++){
        int pos = tknp(k-a[i]*a[i],1,i-1);
        if ( pos > 0 )
            ans ++;
    }
    cout << ans ;
    return 0;
}
