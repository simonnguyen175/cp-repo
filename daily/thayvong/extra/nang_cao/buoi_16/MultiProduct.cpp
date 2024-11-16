#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int K=1e6+1;
const int N=6;

int k, n;
ll f[N][K], ans[6];



int main(){
    freopen("MultiProduct.inp","r",stdin);
    freopen("MultiProduct.out","w",stdout);
    cin >> k >> n;

    // n=2
    for (int u=1; u<=sqrt(k); ++u)
        for (int v=u; v<=k/u; ++v)
            if ( u == v ) f[2][u*v]++;
            else f[2][u*v]+=2;
    for (int i=1; i<=k; ++i)
        f[2][i] += f[2][i-1];
    // n=3
    ans[3]=0;
    for  (int u=1; u<=k; u++)
        ans[3]+=f[2][k/u];

    // n=4
    for (int i=1; i<=k; i++) f[2][i]=0;
    for (int u=1; u<=sqrt(k); ++u)
        for (int v=u; v<=k/u; ++v)
            if ( u == v ) f[2][u*v]++;
            else f[2][u*v]+=2;
    ans[4]=0;
    for (int u=1; u<=sqrt(k); ++u)
        for (int v=u; v<=k/u; ++v)
            if ( v == u ) f[4][u*v]+=f[2][u]*f[2][v];
            else f[4][u*v]+=2*f[2][u]*f[2][v];
    for (int i=1; i<=k; i++)
        f[4][i]+=f[4][i-1];
    ans[4]=f[4][k];

    // n=5
    ans[5]=0;
    for (int u=1; u<=k; u++)
        ans[5]+=f[4][k/u];
    cout << ans[n];
    return 0;
}
