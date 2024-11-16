#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3 + 5;
const int MOD = 1e9 + 7;

int n, k;
int f[N][N];

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

    cin >> n >> k;

    f[0][0] = 1;
    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= min(i, k); j ++){
        f[i+1][j] = add(f[i+1][j], mul(j+1, f[i][j]));
        f[i+1][j+1] = add(f[i+1][j+1], mul(i-j, f[i][j]));
    }

    cout << f[n][k];

    return 0;
}
