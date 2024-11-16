#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d;
int main()
{
    freopen("GIAIPT4.inp","r",stdin);
    freopen("GIAIPT4.out","w",stdout);
    cin>>a>>b>>c;
    d=b*b-4*a*c;
    if (a==0)
        {
            if (b==0)
                {
                    if (c==0) cout<<"phuong trinh vo so nghiem";
                    else cout<<"phuong trinh vo nghiem";
                }
            else
                cout<<(float)-c/b;
        }
    else
            if (d>=0)
            {
               if (d>0 && -b/a>0 && c/a>0) cout<<"phuong trinh co 4 nghiem";
               if (d>0 && -b/a>0 && c/a==0) cout<<"phuong trinh co 3 nghiem";
               if ( c/a<0 || (d==0 && -b/a>0)) cout<<"phuong trinh co 2 nghiem";
               if ((d==0 && -b/a==0 && c/a==0) || (d>0 && -b/a<0 && c*a==0)) cout<<"phuong trinh co 1 nghiem";
               if (c/a>0 && -b/a<0) cout<<"phuong trinh vo nghiem";
            }
            else
                cout<<"phuong trinh vo nghiem";
}
