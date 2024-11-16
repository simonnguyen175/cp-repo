#include <bits/stdc++.h>
using namespace std;
long long n,a[100001],res=0,dem=1;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n ;
    for (int i=1; i<=n; i++) cin >> a[i];
    sort (a+1,a+1+n);
    a[n+1]=INT_MAX;
    for (int i=2; i<=n+1; i++)
    {
        if (a[i]==a[i-1]) dem++;
        else
        {
            if (dem >=3 && a[i-1] > 0) res+=(dem*(dem-1)*(dem-2)/6);
            dem=1;
        }
    }
    cout << res;
    return 0;
}
