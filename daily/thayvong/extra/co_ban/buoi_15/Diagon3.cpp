#include <bits/stdc++.h>
using namespace std;

struct rect{
    int x, y, s;
};

bool compair(rect a, rect b){
    return (a.s > b.s);
}

bool check(int u, int v, int i, int j){
    for (int e=0; e<=2; e++)
        for (int f=0; f<=2; f++)
            if ( u+e == i+f && v+e == j-f )
                return false;
    return true;
}

int n, m;
int a[1001][1001];
rect d[10000002];

int main(){
    freopen("Diagon3.inp","r",stdin);
    freopen("Diagon3.out","w",stdout);
    ios :: sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n >> m;
    int ans=INT_MIN;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin >> a[i][j];
    int k=0;
    for (int i=1; i<=n-2; i++)
        for (int j=1; j<=m-2; j++){
            k++;
            d[k].x=i; d[k].y=j;
            d[k].s=a[i][j]+a[i+1][j+1]+a[i+2][j+2];
        }
    sort (d+1,d+1+k, compair);
    for (int i=1; i<=n-2; i++)
        for (int j=3; j<=m; j++){
            for (int l=1; l<=k; l++){
                int u=d[l].x, v=d[l].y;
                if ( check(u,v,i,j) ){
                    ans = max(ans, d[l].s+a[i][j]+a[i+1][j-1]+a[i+2][j-2]);
                    break;
                }
            }
        }
    cout << ans;
    return 0;
}
