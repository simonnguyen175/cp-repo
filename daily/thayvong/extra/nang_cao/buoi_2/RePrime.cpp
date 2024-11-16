#include <bits/stdc++.h>
using namespace std;
long long  n,i,dem[1000001];
int main()
{
    freopen("reprime.inp","r",stdin);
    freopen("reprime.out","w",stdout);
    cin >> n;
    i=2;
    while (n>1)
        {
            while (n % i == 0)
                {dem[i]++; n/=i;}
            i++;
        }
    for (int j=1; j<=i; j++)
        {
            if (dem[j]>0) cout<<j<<" "<<dem[j];
            else continue;
            cout << endl;
        }
}
