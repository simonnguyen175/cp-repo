#include <bits/stdc++.h>
using namespace std;
int n,a[100001];
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
    cin >> n ;
    int c=0,res=INT_MIN;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=2; i<=n; i++)
        if ((a[i]+a[i-1]) % 2 ==1 )
        {
            res=max(res,a[i]+a[i-1]);
            c=1;
        }
    if (c==0) cout << -1;
    else cout << res;
    return 0;
}
