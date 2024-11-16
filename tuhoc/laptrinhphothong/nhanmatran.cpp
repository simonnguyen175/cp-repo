#include <bits/stdc++.h>
using namespace std;
int a[10][10],b[10][10],c[10][10],i,j,n,m,p,k;
int main()
{
    cin >> n >> m >> p;
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            cin >> a[i][j];
    for (i=1; i<=m; i++)
        for (j=1; j<=p; j++)
            cin >> b[i][j];
    for (i=1; i<=n; i++)
        for (j=1; j<=p; j++)
        {
            c[i][j]=0;
            for (k=1; k<=m; k++)
                c[i][j]=c[i][j] + a[i][k]*b[k][j];
        }
    for (i=1; i<=n; i++)
        {
            for (j=1;j<=p; j++)
            cout << c[i][j] <<" ";
            cout << endl;
        }
}
