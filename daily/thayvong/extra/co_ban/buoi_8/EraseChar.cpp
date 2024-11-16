#include <bits/stdc++.h>
using namespace std;
string  s,temp;
int n,k;
bool palin(string s)
{
    string temp=s;
    reverse(s.begin(), s.end());
    if (temp==s) return true;
    else return false;
}
int main()
{
    cin >> n >>k;
    cin >> s;
    s=' '+s;
    for (int i=1; i<=n;i++)
        for (int j=i; j<=n; j++)
            {
                temp=s.substr(i,j-i+1);
                if (palin(temp)==1 && i-1+n-j==k)
                {cout << temp; return 0;}
            }
    cout << "No";
    return 0 ;
}
