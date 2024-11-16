#include<bits/stdc++.h>
using namespace std;
long long j,i,n,h,nho,res,x,s[200002],a[200002];
int main()
{
    freopen("increasing.inp","r",stdin);
    freopen("increasing.out","w",stdout);
    cin >> n >> h;
    for(int i=1 ; i<=n ;++i) cin >> a[i];

    for(int i=1 ; i<=n ; ++i) s[i] = s[i-1] +a[i];
    nho = (h+1) *h/2;
    a[0] =0;
    res = 1e18;
    j = n+1;
    i = n;
    while(i>=1)
    {
        if(a[i] <= h - (j-i-1) )
        {
            if( (j - i) == h)
            {
                if(s[j-1] - s[i-1] <=nho) res = min(res, nho - (s[j-1]-s[i-1]) );
                j--;
            }
            i--;
        }
        else
        {
            j--;
            if(j == i) i--;
        }
    }
    if(res !=1e18) cout<<res;else cout<<-1;
}
