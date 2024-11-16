#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int m, n;
int fact[N];

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

int Pow(int a, int b){
    if ( b == 0 ) return 1;
    int tmp = Pow(a, b/2);
    if ( b % 2 ) return mul(tmp, mul(tmp, a));
    else return mul(tmp, tmp);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("matrix.inp", "r", stdin);
    freopen("matrix.out", "w", stdout);

    cin >> m >> n;
    fact[0] = 1;
    for (int i = 1; i <= m; i ++)
        fact[i] = mul(fact[i-1], i);

    if ( m > n ) swap(m, n);
    int ans = 1;
    for (int i = 1; i < m; i ++)
        ans = mul(ans, mul(fact[i], fact[i]));
    ans = mul(ans, Pow(fact[m], n-m+1));

    cout << ans;

    return 0;
}
