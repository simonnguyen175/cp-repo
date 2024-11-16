#include <bits/stdc++.h>
using namespace std;

int l;
long long f[202][202];

int main(){
    freopen("cutwood12.inp","r",stdin);
    freopen("cutwood12.out","w",stdout);
    cin >> l;
    for (int i=1; i<=l; i++)
        f[i][1]=1;
    for (int i=1; i<=12; i++)
        f[i][i]=1;

    for (int t=2; t <=12 ; t++)
        for (int i=t+1 ; i<=l; i++){
            for (int e=t-1; e <=i-1; e++)
                f[i][t]+=f[e][t-1];
        }
    cout << f[l][12];
    return 0;
}
