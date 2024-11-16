#include <bits/stdc++.h>
using namespace std;

int n, k, a[1001];
int f[1001][1001];

int main(){
    freopen("SPLITSEQ.inp","r",stdin);
    freopen("SPLITSEQ.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n >> k ;
    for (int i=1; i<=n; i++) cin >> a[i];
    f[1][1]=a[1];
    for (int i=1; i<=n; i++) f[i][1]=max(f[i-1][1], a[i]);
    for (int i=2; i<=n; i++)
        for (int t=2; t<= min(i,k); t++){
            f[i][t]=f[i-1][t-1]+a[i];
            int x=a[i];
            for (int j=i-1; j>=t; j--){
                x=max(x,a[j]);
                f[i][t]=min(f[i][t], f[j-1][t-1]+x);
            }
        }
    cout << f[n][k];
    return 0;
}
