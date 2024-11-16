#include <bits/stdc++.h>
using namespace std;

int tknp(int a[],int d,int c,int x)
{
    res
    int l=d, r=c;
    while ( l <= r )
    {
        int mid = (l + r) / 2;
        if (x == a[mid]) return 1;
        else
            if (x < a[mid]) r = mid - 1 ;
            else
                l = mid +1;
    }
    return res;
}

int a[100001] , b[100001];
int n , m ;

int main()
{
    cin >> n >> m ;
    for (int i=1; i <= n; i++)
        cin >> a[i];
    for (int i=1; i <= m; i++)
        cin >> b[i];
    for (int i=1; i<=m ; i++)
        cout << tknp(a, 1, n, b[i]);
    return 0;
}
