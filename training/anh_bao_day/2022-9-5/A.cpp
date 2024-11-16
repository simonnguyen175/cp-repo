#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
const int MOD = 998244353;

int n;
int a[N], f[N*N][N], fact[N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    return a;
}

int mul(int a, int b){
    return 1LL * a * b % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        sum += a[i];
    }

    if ( sum % 2 ){
        cout << 0;
        return 0;
    }

    fact[0] = 1;
    for (int i = 1; i <= n; i ++)
        fact[i] = mul(fact[i-1], i);

    f[0][0] = 1;
    for (int i = 1; i <= n; i ++)
    for (int j = sum; j >= a[i]; j --)
    for (int k = i; k >= 1; k --)
        f[j][k] = add(f[j][k], f[j-a[i]][k-1]);

    int ans = 0;
    for (int i = 1; i < n; i ++)
        ans = add(ans, mul(f[sum/2][i], mul(fact[i], fact[n-i])));

    cout << ans;

    return 0;
}
