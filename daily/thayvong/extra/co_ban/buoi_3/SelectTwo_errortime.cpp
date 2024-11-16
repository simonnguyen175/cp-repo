#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100000],b[100000],i,j,k,s,ans;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n>>m;
    for (i=1; i<=n; i++) cin>>a[i];
    for (i=1; i<=m; i++) cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    i=1; j=1; k=0; s=0; ans=0;
    if (n<m)
    {
        while (i<=n)
        {
            if (a[i]==b[j]) {s=2*a[i]; k=1; if (s>ans) ans=s; ; i++; j++; if (j>m) break; else continue;}
            if (a[i]<b[j]) {i++; continue;}
            if (a[i]>b[j]) {j++; if (j>m) break; else continue;}
        }
    }
    else
    {
        while (i<=m)
        {
            if (b[i]==a[j]) {s=2*b[i]; k=1; if (s>ans) ans=s; i++; j++; if (j>n) break; else continue;}
            if (b[i]<a[j]) {i++; continue;}
            if (b[i]>a[j]) {j++; if  (j>n) break; else continue;}
        }
    }
    if (k==0) cout<<"No";
    else cout<<ans;
}
