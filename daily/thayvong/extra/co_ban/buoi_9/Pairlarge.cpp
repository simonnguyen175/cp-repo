#include <bits/stdc++.h>
using namespace std;
int n,a[200001],x;
int binsearch(int arr[],int d, int c,int x){
    int r=c;
    int l=d;
    int mid,res=0;
    while (l<=r){
        mid=( l + r )/2;
        if (arr[mid] >= x){
            res = mid;
            r = mid-1;
        }
        else
            l = mid+1;
    }
    return res;
}
int main(){
    cin >> n >> x;
    long long  ans=0,temp,pos;
    for (int i=1; i<=n; i++) cin >> a[i];
    sort (a+1,a+1+n);
    for (int i=1; i<=n-1; i++)
    {
        temp = x - a[i];
        if (a[n] < temp) continue;
        else
        {
            pos= binsearch(a,i+1,n,temp);
            ans += (n-pos+1);
        }
    }
    cout << ans ;
    return 0 ;
}
