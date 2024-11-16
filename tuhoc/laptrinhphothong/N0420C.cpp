#include <bits/stdc++.h>
using namespace std;
long long n,a[100000],b[100000],c[200000],i,p,q;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n; p=1;q=2;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>b[i];
        c[p]=a[i]; c[q]=b[i];
        p=q+1;q=q+2;
    }
    sort(c+1,c+1+2*n,greater<long long>());
    for(i=1;i<=2*n;i++) cout<<c[i]<<" ";
}

