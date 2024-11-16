#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, a[3*N];
long long f[3*N], g[3*N];

int main(){
    cin >> n;
    for (int i = 1; i <= 3*n; i ++)
        cin >> a[i];

    multiset<int> cont; long long s = 0;
    for (int i = 1; i <= n; i ++){
        cont.insert(a[i]); s += a[i];
    }
    f[n] = s;

    for (int i = n + 1; i <= 3*n; i ++){
        s += a[i]; cont.insert(a[i]);
        int v = *cont.cbegin();
        s -= v; cont.erase(cont.find(v));
        f[i] = s;
    }

    cont.clear(); s = 0;
    for (int i = 3*n; i >= 3*n - n + 1; i --){
        cont.insert(a[i]); s += a[i];
    }
    g[3*n-n+1] = s;

    for (int i = 2 * n; i >= 1; i --){
        s += a[i]; cont.insert(a[i]);
        int v = *cont.rbegin();
        s -= v; cont.erase(cont.find(v));
        g[i] = s;
    }

    long long ans = LLONG_MIN;
    for (int i = n; i <= 2*n; i ++)
        ans = max(ans, f[i] - g[i+1]);
    cout << ans;
    return 0;
}
