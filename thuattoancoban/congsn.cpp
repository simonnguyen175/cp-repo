#include <bits/stdc++.h>
using namespace std;

string a,b;
int Lena, Lenb;

void solve(string a, string b)
{
    string c = "";
    int x, y,
        sum, carry=0 ;
    for (int i = Lena; i>=1; i--)
    {
        x = a[i]-'0';
        y = b[i]-'0';

        sum = x + y + carry;
        carry = sum / 10;
        c = char(sum % 10 +'0') + c ;
    }
    if ( carry > 0 ) c='1'+c;
    cout << c;
}

int main()
{
    freopen("congsn.inp","r",stdin);
    freopen("congsn.out","w",stdout);

    cin >> a >> b ;

    while (a.size() < b.size())
        a='0'+a;
    while  (b.size() < a.size())
        b='0'+b;
    Lena=a.size();
    Lenb=b.size();
    a=' '+a;
    b=' '+b;

    solve(a,b);
    return 0;
}
