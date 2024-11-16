#include <bits/stdc++.h>
using namespace std ;
int n,a[1001],q,l[11],r[11];
int invert (int l, int r)
{
    int dem=0;
    for (int i=l; i<=r-1; i++)
        for (int j=i+1; j<=r; j++)
                if (a[i] > a[j]) dem ++;
    return dem ;
}
int main()
{
    cin >> n >> q ;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=q; i++)
        cin >> l[i] >> r[i];
    for (int i=1; i<=q; i++)
        cout << invert(l[i],r[i]) <<"\n";
}

