#include <bits/stdc++.h>
using namespace std;

int n, a[101], x;
long long s=0;

int main(){
    freopen("calsum.inp", "r", stdin);
    freopen("calsum.out", "w", stdout);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    cin >> x;
    for (int i=1; i<=n; i++)
        s += abs(a[i]-x);
    cout << s;
    return 0;
}
