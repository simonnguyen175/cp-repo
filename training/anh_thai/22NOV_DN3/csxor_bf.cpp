#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int n;
int a[N], pw2[N];

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    return a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    pw2[0] = 1;
    for (int i = 1; i <= n; i ++)
        pw2[i] = mul(pw2[i-1], 2);

    int ans = 0;
    for (int i = 1; i <= n; i ++){
        ll cur = 0;
        for (int j = i; j <= n; j ++){
            cur ^= a[j];
            if ( cur == 0 && j > i ) ans = add(ans, pw2[j-i+1]-2);
        }
    }

    cout << ans;

    return 0;
}
