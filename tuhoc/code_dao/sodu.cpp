#include<bits/stdc++.h>
using namespace std;
#define int long long
long long n,k,a[1000006],b[1000006],c[1000005],kq=0,kq1=0;

long long tim(long long x)
{
    long long trc=1, sau=n, kq=-1;
    while(trc<=sau)
    {
        if(a[1]>x)
            return 0;
        else
        {
        long long giua =(trc +sau)/2;
        if(a[giua]<=x)
        {
            kq=a[giua];
            trc=giua+1;
        }
        else
        {
            sau=giua-1;
        }
        }
    }
    return kq;
}

signed main()
{
    freopen("sodu.inp", "r", stdin);
    freopen("sodu.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();

    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];

    sort(a+1, a+n+1);

    for(int i=1; i<=n; i++)
    {
        for(int j=a[i]; j<=(int)1e6; j+=a[i])
        {
            int s=tim(j+a[i]-1);
//            cout << a[i] << ' ' << s << '\n';
            if ( s != -1 )
                kq1=max(kq1, s%a[i]);
        }
    }
    cout<<kq1;
    return 0;
}
