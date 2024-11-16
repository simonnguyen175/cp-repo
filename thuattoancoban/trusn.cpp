#include <bits/stdc++.h>
using namespace std;

string a,b;
int Lena, Lenb;

string solve(string a, string b)
{
    string c="";
    int x, y,
        s, borrow=0;

    for (int i=Lena; i >=1; i--)
    {
        x = a[i]-'0';
        y = b[i]-'0';

        s=x-y-borrow;
        if ( s < 0 )
        {
            s+=10;
            borrow=1;
        }
        else
            borrow=0;
        c=char(s+'0')+c;
    }
    while ( c.size() > 1 && c[0] == '0') c.erase(0,1);
    return c;
}

int main()
{
    freopen("trusn.inp","r",stdin);
    freopen("trusn.out","w",stdout);

    cin >> a >> b ;

    while (a.size() < b.size())
        a='0'+a;
    while  (b.size() < a.size())
        b='0'+b;
    Lena=a.size();
    Lenb=b.size();
    a=' '+a;
    b=' '+b;
    if (a>=b)
        cout << solve(a,b);
    else  cout << "-"<<solve(b,a);
    return 0;
}
