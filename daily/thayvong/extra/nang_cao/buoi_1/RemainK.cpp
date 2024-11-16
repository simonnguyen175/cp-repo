#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500001],s[500001],i,j,dem=0;
int main()
{
    freopen("RemainK.inp","r",stdin);
    freopen("RemainK.out","w",stdout);
    cin>>n>>k;
    for (i=1; i<=n; i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for (i=0; i<=n-1; i++)
        for (j=i+1; j<=n; j++)
            if ((s[j]-s[i]) % k== (j-i)) dem++;
    cout << dem;
}
