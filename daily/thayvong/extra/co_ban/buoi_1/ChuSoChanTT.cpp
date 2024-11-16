#include <bits/stdc++.h>
using namespace std;
long long a,b;
int main()
{
    cin>>a;
    b=a%10;
    a=a/10;
    if (a%2==0)
        {
            if (b%2==0)
            {
                if (a>b) {cout<<b<<"\n";cout<<a;}
                    else {cout<<a<<"\n";cout<<b;}
            }
        else cout<<a;
        }
    else
        if (b%2==0) cout<<b;
            else cout<<"Khong co chu so chan";
}
