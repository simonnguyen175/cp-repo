#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n;
double k[N], c[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> k[i];
    for (int i = 1; i <= n; i ++) cin >> c[i];

    double ans = 0.0;
    for (int i = 1; i <= n; i ++)
        ans += 1.0/k[i] + 1.0 * k[i] * c[i];

    cout << fixed << setprecision(2) << ans / 2.0;

    return 0;
}
