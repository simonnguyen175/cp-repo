#include <bits/stdc++.h>
using namespace std;
long long a[10001],n,i,j,k,l[21],r[21];
bool ktra(long long i,long long j)
{
    sort (a+i,a+j+1);long long t;
    if (i==j)
        if (a[i]==1) return true;
            else return false;
    for (t=i+1; t<=j; t++)
    {
        if (a[t]>j-i+1 || a[t]<1) return false;
        if (a[t]-a[t-1] != 1) return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n>>k;
    for (i=1; i<=n; i++) cin>>a[i];
    /*for (i=1; i<=k; i++)
        cin>>l[i]>>r[i];
    for (i=1; i<=k; i++)
    {
        if (ktra(l[i],r[i])) cout<<1;
        else cout<<0;
        cout<<endl;
    }
    return 0; */
    sort (a+1,a+1+4);long long t;
    if (1==4)
        {if (a[1]==1) cout<<1;
            else cout<<0;}
    for (t=2; t<=4; t++)
    {
        if (a[t]>j-i+1 || a[t]<1) {cout<<0;return 0;}
        if (a[t]-a[t-1] != 1) {cout<<0; return 0; }
    }
    cout<<1;
}
