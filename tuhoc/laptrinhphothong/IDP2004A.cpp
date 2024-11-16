#include <bits/stdc++.h>
using namespace std;

int n,q;
int a[100001], l[100001];
int f[100001];

int main(){
    //INPUT&&SETUP
    cin >> n >> q;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=q; i++)
        cin >> l[i];
    //SOLVE
    memset(f, 0,sizeof f);
    f[0]=0;
    for (int i=1; i<=n; i++)
        if ( a[i] > 0 )
            f[i]=f[i-1]+1;
        else
            f[i]=f[i-1];
    for (int i=1; i<=q; i++)
        cout << f[l[i]]<<"\n";
    return 0;
}
