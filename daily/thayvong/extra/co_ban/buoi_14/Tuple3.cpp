#include <bits/stdc++.h>
using namespace std;

int n, a[200001];
long long ans =0,l;

int main(){
    freopen("Tuple3.inp","r",stdin);
    freopen("Tuple3.out","w",stdout);
    cin >>  n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    sort (a+1,a+1+n);
    int i=1;
    for (int k=3; k <=n; k++){
        while ( a[k] - a[i] > 2 )
            i++;
        l = k-i;
        ans += l*(l-1)/2;
    }
    cout << ans;
    return 0;
}
