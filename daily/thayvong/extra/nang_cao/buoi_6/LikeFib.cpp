#include <bits/stdc++.h>
using namespace std;

int n,f[1000001];

int main(){
    freopen("LikeFib.inp","r",stdin);
    freopen("LikeFib.out","w",stdout);
    cin >> n ;
    f[1]=1;
    f[2]=1;
    for (int i=3; i<=n; i++){
        f[i] = (f[i-1]%2019+2*f[i-2]%2019)%2019;
    }
    cout << f[n];
}
