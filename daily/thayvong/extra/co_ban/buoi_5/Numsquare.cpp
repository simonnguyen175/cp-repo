#include <bits/stdc++.h>
using namespace std;
long long a,b;
int main()
{
    cin>>a>>b;
    long  long l=(int)sqrt(a), r=(int)sqrt(b);
    if (l*l<a) l++;
    cout<<r-l+1;
}
