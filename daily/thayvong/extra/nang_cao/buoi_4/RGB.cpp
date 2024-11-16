#include <bits/stdc++.h>
using namespace std;
long long n, nr=0, ng=0, nb=0;
string st;

int main()
{
    freopen("RGB.inp","r",stdin);
    freopen("RGB.out","w",stdout);
    cin >> n ;
    cin >> st ;
    for (int i=0; i<n; i++)
    {
        if (st[i]== 'R') nr++;
        if (st[i]== 'G') ng++;
        if (st[i]== 'B') nb++;
    }
    long long s= nr*nb*ng;
    for (int i=0; i<= n-3; i++)
        for (int j=i+1; j<=n-2; j++)
        {
            if (st[i]==st[j]) continue;
            int k=2*j-i;
            if (k<n && st[k] != st[i] && st[k] != st[j])
                s--;
        }
    cout << s ;
}
