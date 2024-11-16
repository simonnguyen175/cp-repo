#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d,ln;
int main()
{
    cin>>a>>b>>c>>d;
    ln=max(a,b);
    ln=max(ln,c);
    ln=max(ln,d);
    cout<<ln;
}
