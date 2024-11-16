#include <bits/stdc++.h>
using namespace std;
long long  n,a,b[1000000],check;
bool cp(long long a)
{
    if (sqrt(a)==(long long)sqrt(a)) return true ;
    else return false;
}
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    n=1; check=0;
    while (cin>>a)
    {
        if (cp(a)==true) {b[n]=a; check=1;n++;}
    }
    if (check==0) cout<<"-1";
    else cout<<b[1];
}
