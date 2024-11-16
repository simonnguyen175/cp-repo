#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 505;
const ll inf = 1e17;

int n, m, i, j, k, a[N][N];
ll tmp, ans, l[N], r[N], row[N][N], col[N][N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if( fopen("CHOOSE2.inp", "r") )
    {
        freopen("CHOOSE2.inp", "r", stdin);
        freopen("CHOOSE2.out", "w", stdout);
    }

    memset(l, -0x3f, sizeof(l));
    memset(r, -0x3f, sizeof(r));

    cin >> n >> m;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            cin >> a[i][j];

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            row[i][j] = row[i][j-1]+a[i][j];
            col[i][j] = col[i-1][j]+a[i][j];
        }

    ans = -inf;
    for(i=1; i<n; i++)
        for(k=i+1; k<=n; k++)
        {
            tmp = -inf;
            for(j=1; j<=m; j++)
                l[j] = max(l[j-1], -row[i][j-1]-row[k][j-1] +col[k-1][j]-col[i][j] );

            for(j=m; j>=1; j--)
                r[j] = max(r[j+1], row[i][j]+row[k][j] + col[k-1][j]-col[i][j] );

            for(j=1; j<m; j++) tmp = max( tmp, l[j]+r[j+1] );

            ans = max( ans, tmp );
        }

    cout << ans;
    return 0;
}
