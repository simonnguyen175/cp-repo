#include<bits/stdc++.h>
#define ll long long
using namespace std;

int c, d, m, sum, b;
ll x, k;
map<int, int> cnt;


int calc( ll a )
{
    int res = 0;
    while( a>0 )
    {
        res += a%b;
        a /= b;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if( fopen("BaseB.inp", "r") )
    {
        freopen("BaseB.inp", "r", stdin);
        freopen("BaseB.out", "w", stdout);
    }

    cin >> c >> d >> b >> m;

    x = 1;
    while( true )
    {
        sum = calc( x*c+d );
        cnt[sum]++;
        if( cnt[sum]==m ) break;
        x += (b-1);
    }

    k = 1;
    while( k<=x )
    {
        if( calc( k*c+d ) == sum ) cout << k << ' ';
        k += (b-1);
    }

    return 0;
}
