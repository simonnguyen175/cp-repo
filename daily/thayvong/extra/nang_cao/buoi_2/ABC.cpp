#include <bits/stdc++.h>
using namespace std;
string s;
int n,i,j,dema,demb,demc,dem;
int main()
{
    freopen("ABC.inp","r",stdin);
    freopen("ABC.out","w",stdout);
    cin >> s ; n=s.size();
    s=' '+s; dema=0; demb=0; demc=0;
    for (i=1; i<=n-2; i++)
    {
        dema=demb=demc=0;
        for (j=i; j<=n; j++)
        {
            if (s[j]=='A') dema++;
            if (s[j]=='B') demb++;
            if (s[j]=='C') demc++;
            if (dema==demb && demb==demc && dema+demb+demc==j-i+1) dem++;
        }
    }
    cout << dem;
}
