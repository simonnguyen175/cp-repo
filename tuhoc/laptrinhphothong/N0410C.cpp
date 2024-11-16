#include <bits/stdc++.h>
using namespace std;
long long n,a[1000000],b[1000000],i,j,t,ln,check;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n; ln=0; check=0;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
        b[a[i]]++;
        ln=max(ln,a[i]);
    }
    for (i=1;i<=ln;i++) if (b[i]==3) {cout<<i<<" ";check=1;}
    for (i=1;i<=ln;i++) if (b[i]%3==0 && b[i]>3)
        {
            t=b[i]/3;
            for (j=1;j<=t;j++) cout<<i<<" ";
            check=1;
        }0
    if (check==0) cout<<"0";
}
