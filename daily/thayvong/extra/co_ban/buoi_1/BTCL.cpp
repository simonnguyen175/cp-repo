#include <bits/stdc++.h>
using namespace std;
long long a,b;
int main()
{
    cin>>a>>b;
    a=(a+1)*(a+1)+b*(b+3);
    if (a%2==0) cout<<"P chan";
    else cout<<"P le";
}
