#include <bits/stdc++.h>
using namespace std;
#define int long long
long long n,a[1000005],kq=0,s=1,c[1000005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(long long i=1; i<=n; i++)
    {
        cin>>a[i];
    }

    if(n <= 1000)
    {
        for(int i=1; i<=n; i++)
        {
            for (int j=i+1; j <= n; j ++)
                kq=max(kq, __gcd(a[i], a[j]));
        }
        cout<<kq;

    }
    else
    {
        for(int i=1; i<=n; i++)
            c[a[i]]++;

        for(int i=1e6+4; i>=1; i--)
        {   // for i la uoc
            kq=0;
            for(int j=i; j<1e6+5; j+=i)
            {
                kq+=c[j]; // so luong so la boi cua j
                if(kq>=2)
                {
                    cout<<i;
                    return 0;
                }
            }
        }
    }
    return 0;
}
