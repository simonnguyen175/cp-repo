#include <bits/stdc++.h>
using namespace std;
string s;
long long i,dem;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>s;
    for (i=0; i<= s.length(); i++)
    {
        if (s[i]<='9' && s[i]>='0') dem++;
    }
    cout<<dem;
}
