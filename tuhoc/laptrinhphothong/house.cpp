#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
    cin >> n;
    cin >> s;
    s=' '+s;
    int i = 2, dem = 1, ans = 0 ;
    while (i<=n)
        {
            while (s[i]==s[i-1])
            {
                dem++;
                i++;
            }
            ans += dem/2;
            dem=1;
            i++;
        }
    cout << ans ;
    return 0;
}
