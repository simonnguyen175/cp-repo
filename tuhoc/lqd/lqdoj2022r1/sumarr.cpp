#include<bits/stdc++.h>
#define BIT(x, k) ((x>>k)&1)
using namespace std;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

int n;
int a[N], f[N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1LL * a * b % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i ++){
        cin >> a[i];
        f[i] = add(f[i], a[i]);
    }

    for (int j = 0; j < 19; j ++)
    for (int i = 0; i < n; i ++) if ( BIT(i, j) )
        f[i] = add(f[i], f[i^(1<<j)]);

    for (int i = 0; i < n; i ++)
        f[i] = mul(f[i], f[i]);

    for (int j = 0; j < 19; j ++)
    for (int i = 0; i < n; i ++) if ( BIT(i, j) )
        f[i] = add(f[i], -f[i^(1<<j)]);

    cout << f[0] << ' ';
    for (int i = 1; i < n; i ++){
        f[i] = add(f[i-1], f[i]);
        cout << f[i] << ' ';
    }


    return 0;
}
