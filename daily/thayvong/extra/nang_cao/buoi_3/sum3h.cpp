#include <bits/stdc++.h>
using namespace std;

int tknp(int a[],int l,int r,int x)
{
    int mid, res=0;
    while ( l <= r )
    {
        mid = ( l + r )/2;
        if ( a[mid] == x )
        {
            res=mid;
            r--;
        }
        else
            if ( a[mid] > x ) r--;
                else l++;
    }
    return res;
}

int n, x, a[2001], ans=0;

int main()
{
        freopen("sum3h.inp","r",stdin);
        freopen("sum3h.out","w",stdout);
        cin >> n >> x ;
        for (int i=1; i<=n; i++) cin >> a[i];
        sort (a+1,a+1+n);
        int l=1, r=n;
        while ( l+1 < r ){
            if (a[l] + a[r] > x){
                r--;
                continue;
            }
            else{
                if (a[l] + a[r] < x){
                    if ( tknp(a,l+1,r-1,x-a[l]-a[r]) > 0 ){
                        int pos = tknp(a,l+1,r-1,x-a[l]-a[r]);
                        int i = pos + 1 ;
                        int dem = 1;
                        while (a[pos] == a[i]){
                            dem++;
                            i++;
                        }
                        ans += dem;
                    }
                l++;
                }
                else{
                    if ( tknp(a,l+1,r-1,0) > 0 ){
                        int pos = tknp(a,l+1,r-1,0);
                        int i = pos + 1 ;
                        int dem = 1;
                        while (a[pos] == a[i]){
                            dem++;
                            i++;
                        }
                        ans += dem;
                    }
                    r--;
                }
            }
        }
        cout << ans ;
}
