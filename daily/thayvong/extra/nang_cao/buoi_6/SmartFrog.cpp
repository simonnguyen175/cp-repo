#include <bits/stdc++.h>
using namespace std;

int n, a[100001], f[100001];
char b[100001];

int main(){
    freopen("SmartFrog1.inp","r",stdin);
    freopen("SmartFrog1.out","w",stdout);
    cin >> n ;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    b[1]='1';
    b[2]='1';
    f[1]=a[1];
    f[2]=abs(a[1]-a[2]);
    for (int i=3; i<=n; i++){
        b[i]='1';
        f[i]=min(f[i-1]+abs(a[i]-a[i-1]), f[i-2]+abs(a[i]-a[i-2]));
        if ( f[i] == f[i-2]+abs(a[i]-a[i-2]) )
            b[i-1]='0';
    }
    cout << f[n] <<"\n";
    for (int i=1; i<=n; i++)
        cout << b[i];
    return 0;
}
