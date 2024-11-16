#include <bits/stdc++.h>
using namespace std;
float a,b,c,d;
int main()
{
    freopen("GIAIPT2.inp","r",stdin);
    freopen("GIAIPT2.out","w",stdout);
    cin>>a>>b>>c;
    d=b*b-4*a*c;
    if (a==0)
        {
            if (b==0)
                {
                    if (c==0) cout<<"vo so nghiem";
                    else cout<<"vo nghiem";
                }
            else
                cout<<(float)-c/b;
        }
    else
        {
            if (d>0)
                cout<<fixed<<setprecision(2)<<(-b-sqrt(d))/(2*a)<<" "<<(-b+sqrt(d))/(2*a);
                else
                    if (d==0) cout<<-b/(2*a);
                        else cout<<"vo nghiem";
        }
}

