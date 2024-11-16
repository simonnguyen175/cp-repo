#include <bits/stdc++.h>
using namespace std;
int n,q,a[100001],x[100001];
int ln(int arr[], int n, int x) {
  int r = n;
  int l = 1;
  int res;
  while (r >= l) {
    int mid = (l + r) / 2;
    if (arr[mid] <= x)
      {
          res=mid;
          l=mid+1;
      }
    else
        r=mid-1;
  }
  return res;
}
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n >> q;
    int pos;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=q; i++) cin >> x[i];
    sort (a+1,a+1+n);
    for (int i=1; i<=q; i++)
    {
        if (x[i] <= a[1]) {cout << a[1]-x[i] <<"\n";continue;}
        if (a[n] <=x[i]) {cout << x[i]-a[n]<<"\n";continue;}
        pos=ln(a,n,x[i]);
        cout << min(  abs( a[pos]-x[i] ) , abs( a[pos+1]-x[i] )  ) <<"\n";
    }
    return 0;
}
