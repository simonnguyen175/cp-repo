#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int N = 1e6 + 5;

int n, k;
long long f[N];

int main(){
    cin >> n >> k;

    if ( k == 1 ) {cout << 1; return 0;}

    f[0] = f[1] = 1;
    long long sum = 2, ans = 0;

    for (int i = 2; i < k; i ++){
        f[i] += sum;
        sum += f[i];
        sum %= MOD;
        f[i] %= MOD;
    }

    for (int i = k; i <= n; i ++){
        sum = sum - f[i-k-1] + MOD * MOD;
        f[i] = sum;
        sum += f[i];
        f[i] %= MOD;
        sum %= MOD;
    }

    for (int i = n - k + 1; i <= n; i ++){
        ans += f[i];
        ans %= MOD;
    }

    cout << ans;

    return 0;
}
