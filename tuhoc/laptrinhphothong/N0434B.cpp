#include <bits/stdc++.h>
using namespace std;
int n,a[1000007],b[1000007],k=1,dem;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
         cin>>a[i];
    b[1]=a[1];
    for (int i=2;i<=n;i++)
     {
        dem=0;
        for (int j=1;j<=(i-1);j++)
            if (a[i]==a[j]) dem=1;
        if (dem==0) {k++;b[k]=a[i];}
     }
    for (int i=1;i<=k;i++)
        cout<<b[i]<<" ";

}
