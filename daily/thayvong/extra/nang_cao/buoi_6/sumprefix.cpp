#include <bits/stdc++.h>
using namespace std;

int n,T,a[100001],s[100001],I;

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cin.tie(0);

    freopen("sumprefix.inp","r",stdin);
    freopen("sumprefix.out","w",stdout);
    cin >> n >> T;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    s[0]=0;
    for (int i=1; i<=n; i++){
        s[i]=s[i-1]+a[i];
    }
    for (int i=1; i<=T; i++){
        cin >> I;
        cout << s[I]<<"\n";
    }
    return 0;
}
