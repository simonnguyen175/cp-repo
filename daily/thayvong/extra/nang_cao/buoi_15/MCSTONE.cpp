#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+1;

int n, a[N];

int main(){
    freopen("MCSTONE.inp","r",stdin);
    freopen("MCSTONE.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    ll s=0, x=0;
    for (int i=1; i<=n; i++){
        x += a[i]-1;
        s += abs(x);
    }
    cout << s;
    return 0;
}
