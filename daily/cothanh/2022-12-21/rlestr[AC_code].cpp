#include<bits/stdc++.h>
#define ll long long
#define ci pair<char, ll>
#define fi first
#define se second
using namespace std;

string s, x, y;
vector<ci> a, b;
int i, n, m; char kt;
ll tmp, p, c, sum[1000];

int cnp(ll x, int k)
{
    if( x==0 ) return -1;

    int l=1, r=k, g, ans=0;

    while(l<=r)
    {
        g = (l+r)/2;

        if( sum[g]>=x )
        {
            ans = g;
            r = g-1;
        }
        else l = g+1;
    }

    return ans-1;

}

void match()
{
    cin >> x >> y;

    n = x.size(); m = y.size();
    a.clear(); b.clear();

    i=0;
    while( i<n )
    {
        kt = x[i];
        i++; tmp=0;
        while( i<n && '0'<=x[i] && x[i]<='9' ) tmp = tmp*10 + x[i]-'0' , i++;
        a.push_back({kt, tmp});
    }

    i=0;
    while( i<m )
    {
        kt = y[i];
        i++; tmp=0;
        while( i<m && '0'<=y[i] && y[i]<='9' ) tmp = tmp*10 + y[i]-'0' , i++;
        b.push_back({kt, tmp});
    }

    n = a.size(); m = b.size();

    for(i=0; i<n-1; i++) cout << a[i].fi << a[i].se;

    if( a[n-1].fi==b[0].fi )
    {
        tmp = a[n-1].se+b[0].se ;
        cout << b[0].fi << tmp;
    }
    else
    {
        cout << a[n-1].fi << a[n-1].se << b[0].fi << b[0].se;
    }


    for(i=1; i<m; i++) cout << b[i].fi << b[i].se;
}

void Delete()
{
    cin >> x >> p >> c;
    memset(sum, 0, sizeof(sum));

    n = x.size(); a.clear();

    i=0;
    while( i<n )
    {
        kt = x[i];
        i++; tmp=0;
        while( i<n && '0'<=x[i] && x[i]<='9' ) tmp = tmp*10 + x[i]-'0' , i++;
        a.push_back({kt, tmp});
    }

    n = a.size();

    for(i=0; i<n; i++) sum[i+1] = sum[i] + a[i].se;

    int pos1=cnp(p-1, n), pos2=cnp(p+c, n);

    if( pos1==-1 && pos2==-1 ) return;

    if( pos1==-1 )
    {
        cout << a[pos2].fi << sum[pos2+1] - (p+c-1);
        for(i=pos2+1; i<n; i++) cout << a[i].fi << a[i].se;
        return;
    }

    if( pos2==-1 )
    {
        for(i=0; i<pos1; i++) cout << a[i].fi << a[i].se;
        cout << a[pos1].fi << p-1 - sum[pos1];
        return;
    }

    for(i=0; i<pos1; i++) cout << a[i].fi << a[i].se;

    if( a[pos1].fi == a[pos2].fi ) cout << a[pos1].fi << sum[pos2+1] - sum[pos1] - c;
    else
    {
        cout << a[pos1].fi << p-1 - sum[pos1];
        cout << a[pos2].fi << sum[pos2+1] - (p+c-1);
    }

    for(i=pos2+1; i<n; i++) cout << a[i].fi << a[i].se;
}

void Copy()
{
    cin >> x >> p >> c;
    memset(sum, 0, sizeof(sum));

    n = x.size(); a.clear();

    i=0;
    while( i<n )
    {
        kt = x[i];
        i++; tmp=0;
        while( i<n && '0'<=x[i] && x[i]<='9' ) tmp = tmp*10 + x[i]-'0' , i++;
        a.push_back({kt, tmp});
    }

    n = a.size();

    for(i=0; i<n; i++) sum[i+1] = sum[i] + a[i].se;

    int pos1=cnp(p, n), pos2=cnp(p+c-1, n);

    if( pos1==pos2 ) cout << a[pos1].fi << c ;
    else
    {
        cout << a[pos1].fi << sum[pos1+1] - p + 1;

        for(i=pos1+1; i<pos2; i++) cout << a[i].fi << a[i].se;

        cout << a[pos2].fi << p+c-1 - sum[pos2];
    }
}

void Insert()
{
    cin >> x >> y >> p;
    memset(sum, 0, sizeof(sum));

    n = x.size(); m = y.size();

    a.clear(); b.clear();

    i=0;
    while( i<n )
    {
        kt = x[i];
        i++; tmp=0;
        while( i<n && '0'<=x[i] && x[i]<='9' ) tmp = tmp*10 + x[i]-'0', i++;
        a.push_back({kt, tmp});
    }

    i=0;
    while( i<m )
    {
        kt = y[i];
        i++; tmp=0;
        while( i<m && '0'<=y[i] && y[i]<='9' ) tmp = tmp*10 + y[i]-'0' , i++;
        b.push_back({kt, tmp});
    }

    n = a.size(); m = b.size();

    for(i=0; i<n; i++) sum[i+1] = sum[i] + a[i].se;

    if( p==sum[n]+1 )
    {
        for(i=0; i<n-1; i++) cout << a[i].fi << a[i].se;

        if( a[n-1].fi==b[0].fi )
        {
            tmp = a[n-1].se+b[0].se ;
            cout << b[0].fi << tmp;
        }
        else cout << a[n-1].fi << a[n-1].se << b[0].fi << b[0].se;

        for(i=1; i<m; i++) cout << b[i].fi << b[i].se;

        return;
    }

    if( p==1 )
    {
        for(i=0; i<m-1; i++) cout << b[i].fi << b[i].se;

        if( b[m-1].fi==a[0].fi )
        {
            tmp = b[m-1].se+a[0].se ;
            cout << a[0].fi << tmp;
        }
        else cout << b[m-1].fi << b[m-1].se << a[0].fi << a[0].se;

        for(i=1; i<n; i++) cout << a[i].fi << a[i].se;

        return;
    }

    int pos1=cnp(p-1, n), pos2=cnp(p, n);

    for(i=0; i<pos1; i++) cout << a[i].fi << a[i].se;

    if( pos1==pos2 )
    {
        if( b[0].fi!=a[pos1].fi && b[m-1].fi!=a[pos2].fi )
        {
           cout << a[pos1].fi << p-1 - sum[pos1];

           cout << y;

           cout << a[pos1].fi << sum[pos2+1] - p + 1;
        }
        else
        {
            if( m==1 ) cout << b[0].fi << a[pos1].se + b[0].se;
            else
            {
                if( b[0].fi==a[pos1].fi )
                {
                    cout << a[pos1].fi << p-1 - sum[pos1] + b[0].se;

                    for(i=1; i<m-1; i++) cout << b[i].fi << b[i].se;

                    if( b[m-1].fi==a[pos2].fi ) cout << a[pos2].fi << sum[pos2+1] - p + 1 + b[m-1].se;
                    else cout << b[m-1].fi << b[m-1].se << a[pos2].fi << sum[pos2+1] - p + 1;
                }
                else
                {
                    cout << a[pos1].fi << p-1 - sum[pos1];

                    for(i=0; i<m-1; i++) cout << b[i].fi << b[i].se;

                    cout << a[pos2].fi << sum[pos2+1] - p + 1 + b[m-1].se;
                }
            }
        }
    }
    else
    {
        if( b[0].fi!=a[pos1].fi && b[m-1].fi!=a[pos2].fi )
        {
           cout << a[pos1].fi << p-1 - sum[pos1];

           cout << y;

           cout << a[pos2].fi << sum[pos2+1] - p + 1;
        }
        else
        {
            if( b[0].fi==a[pos1].fi )
            {
                cout << a[pos1].fi << a[pos1].se + b[0].se;

                for(i=1; i<m-1; i++) cout << b[i].fi << b[i].se;

                if( b[m-1].fi==a[pos2].fi ) cout << a[pos2].fi << a[pos2].se + b[m-1].se;
                else
                {
                    if( m!=1 ) cout << b[m-1].fi << b[m-1].se;
                    cout << a[pos2].fi << a[pos2].se;
                }
            }
            else
            {
                cout << a[pos1].fi << p-1 - sum[pos1];

                for(i=0; i<m-1; i++) cout << b[i].fi << b[i].se;

                cout << a[pos2].fi << a[pos2].se + b[m-1].se;
            }
        }
    }

    for(i=pos2+1; i<n; i++) cout << a[i].fi << a[i].se;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    if( fopen("RLESTR.inp", "r") )
//    {
//        freopen("RLESTR.inp", "r", stdin);
//        freopen("RLESTR.out", "w", stdout);
//    }

    while( cin >> s )
    {
        cout << s << ": ";

        if( s == "@1" ) match();
        if( s == "@2" ) Delete();
        if( s == "@3" ) Copy();
        if( s == "@4" ) Insert();

        cout << '\n';
    }
    return 0;
}
