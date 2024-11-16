#include <bits/stdc++.h>
using namespace std;
long long x,s;
int main()
{
    cin>>x; long long temp=1;
    while (x>0)
    {
        s+=temp;
        temp*=2;
        x/=2;
    }
    cout << s;
}
