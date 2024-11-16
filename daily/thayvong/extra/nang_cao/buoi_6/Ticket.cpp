#include <bits/stdc++.h>
using namespace std;

long long n, a[100001], f[100001];

int main(){
    freopen("Ticket.inp","r",stdin);
    freopen("Ticket.out","w",stdout);
    cin >> n ;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    f[n]=a[n];
    f[n-1]=min(a[n]+a[n-1],a[n-1]*2);
    for (int i=n-2; i>=1; i--){
        f[i]=min( f[i+1]+a[i], f[i+2]+2*a[i]);
    }
    cout << f[1];
    return 0;
}
