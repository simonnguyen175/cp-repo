#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000001],c[1000001];
int SumBlack=0,SumWhite=0,res;
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++)  cin >> c[i];
    int i=1;
    while  (i <= n)
    {
        while (c[i]==0 && SumWhite+a[i]<m)
                {
                    SumWhite+=a[i];
                    i++;
                    if (i>n) break;
                }
        res++; SumWhite=0;
        cout << i <<" "<< res <<endl;
        while (c[i]==1 && SumBlack+a[i] <m)
            {
                SumBlack+=a[i];
                i++;
                if (i>n) break ;
            }
        if (SumBlack > 0)
        {
            res++;
            SumBlack=0;
        }
        cout <<i<<" " << res <<endl;
        i++;
    }
    cout <<res;
}
