#include <bits/stdc++.h>
using namespace std;
const int N=1e6+1;

int n, a[N], b[N], p;

int main(){
    freopen("minout.inp","r",stdin);
    freopen("minout.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    p=0;
    for (int i=1; i<=n; i++){
        b[a[i]]=1;
        while ( b[p] ) p++;
        cout << p <<'\n';
    }
}
