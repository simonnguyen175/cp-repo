#include <bits/stdc++.h>
using namespace std;
float x,y;
int main()
{
    freopen("BIEUTHUC.inp","r",stdin);
    freopen("BIEUTHUC.out","w",stdout);
    cin>>x>>y;
    cout<<fixed<<setprecision(2)<<sqrt((x*x+2*y)/x*y)<<"\n";
    cout<<fixed<<setprecision(2)<<sqrt((4*x*x*x+pow(y,1.0/3))/(2*x+3*y));
}
