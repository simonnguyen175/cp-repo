#include <bits/stdc++.h>
using namespace std;
long long  t,n,i,x,dem[1000001];
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    freopen("ExpressPrime.inp","r",stdin);
    freopen("ExpressPrime.out","w",stdout);
    cin >> t;
    for (int j=1; j<=t; j++)
    {
        cin >> n;
        for (i=2; i<=sqrt(n); i++)
        {
            x=0;
            if (n % i==0)
                while (n % i == 0)
                    {x++; n/=i;}
            if (x  > 0 ){
                cout << i <<" ";
            }
        }
        if (n != 1 ) cout << n <<"\n";
        else cout <<"\n";
    }
}
