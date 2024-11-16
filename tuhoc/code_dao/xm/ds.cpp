#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int n;
int a[N], d[N];

int main(){
    freopen("ds.inp", "r", stdin);
    freopen("ds.out", "w", stdout);

    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        ans += d[a[i]];
        d[a[i]] ++;
    }
    ans = 1ll*n*(n-1)/2 - ans;
    cout << ans;
    return 0;
}
