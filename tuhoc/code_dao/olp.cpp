#include <bits/stdc++.h>
using namespace std;
long long n,m,m1,n1,a[10000005],c3[10000005],c1[10000005],c2[10000005],kq=-1e9;
int main()
{
    freopen("thu.inp", "r", stdin);
    freopen("thu.out", "w", stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        int s1=0,s2=0,s3=0;
        cin>>a[i];

        if(a[i]==1)
            s1=1;
        if(a[i]==2)
            s2=1;
        if(a[i]==3)
            s3=1;
        c1[i]=c1[i-1]+s1;
        c2[i]=c2[i-1]+s2;
        c3[i]=c3[i-1]+s3;
    }
    for(int i=1; i<=m; i++)
    {
        cin>>n1>>m1;
        cout<<c1[m1]-c1[n1-1]<<" "<<c2[m1]-c2[n1-1]<<" "<<c3[m1]-c3[n1-1]<<'\n';
    }
}

