#include <bits/stdc++.h>
using namespace std ;

pair <int , int> a[1000000];
int n, m , b[1000000];

int tknp(pair<int,int> a[],int d,int c,int x)
{
    int res=0;
    int l=d, r=c;
    while ( l <= r )
    {
        int mid = (l + r) / 2;
        if ( x == a[mid].first) {
                res=a[mid].second;
                r=mid-1;
        }
        else
            if (x < a[mid].first) r = mid - 1 ;
            else
                l = mid +1;
    }
    return res;
}

int main()
{
    cin >> n >> m ;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i].first;
        a[i].second=i;
    }
    for (int i=1; i<=m; i++)
        cin >> b[i];
    sort (a+1,a+1+n);
    for (int i=1; i<=m; i++)
        cout << tknp(a,1,n,b[i]) <<" ";
    return 0;
}
