#include <bits/stdc++.h>
using namespace std;
long long n,a[100001],i,c;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n;
    for (i=1; i<=n; i++) cin>>a[i];
    sort (a+1, a+1+n); c=1; a[n+1]=a[n]+1;
    for (i=1; i<=n; i++)
    {
        if (a[i]>n || a[i]<1) {c=0;; break;}
        if (a[i]==a[i+1]) {c=0; break;}
    }
    if (c==0) cout<<"No";
    else cout<<"Yes";
}
