#include <bits/stdc++.h>
using namespace std;
int a[100000],b[100000],n,i,s;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
    for(i=1;i<=n;i++)
        {
            cin>>b[i];
            s=s+abs(a[i]-b[i]);
        }
    cout<<s;
}
