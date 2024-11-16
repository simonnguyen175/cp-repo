#include <bits/stdc++.h>
using namespace std;
long long n,a[100001],b[10],cs,ans,i;
int main()
{
    freopen("chuso.inp","r",stdin);
    freopen("chuso.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (i=1; i<=n; i++) cin >> a[i];
    for (i=1; i<=n; i++)
    {
        while (a[i] > 0)
        {
            cs=a[i] % 10;
            b[cs]++;
            a[i]/=10;
        }
    }
    for (i=0; i<=9; i++)
    {
        if (b[i]>=ans)
        {
            ans=b[i];
            cs=i;
        }
    }
    cout << cs << " " << ans;
}
