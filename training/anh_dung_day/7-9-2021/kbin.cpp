#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1234567;

long long n;
int k, numbit;
bitset<55> bitn;
long long f[55][55], c[55][55], s[55];

void init(){
    cin >> n >> k;
    bitn = bitset<55>(n);
    for (int i = 55; i >= 0; i --)
        if ( bitn[i] == 1 ){
            numbit = i + 1;
            break;
        }

    c[0][0] = 1;
    for (int i = 1; i <= numbit; i ++){
        c[i][0] = 1;
        for (int j = 1; j <= min(i, k); j ++)
            c[i][j] = ( c[i-1][j] + c[i-1][j-1] ) % MOD;
    }

    for (int i = 1; i <= numbit; i ++)
        for (int j = 1; j <= min(i, k); j ++)
            f[i][j] = ( f[i-1][j] * 2 + f[i-1][j-1] * 2 + c[i-1][j-1] ) % MOD;

    long long mu = 2;
    s[0] = bitn[0];
    for (int i = 1; i < numbit; i ++){
        s[i] = ( s[i-1] + mu * bitn[i] % MOD ) % MOD ;
        mu *= 2;
        mu %= MOD;
    }
}

long long get(int i, int k){
    if ( i == 0 ) return 0;

    if ( bitn[i-1] == 1 ){
         if ( k == 0 ) return (s[numbit-1] - s[i-1] + MOD * MOD) % MOD;
        return ( f[i-1][k] % MOD + ( c[i-1][k] % MOD * ((s[numbit-1] - s[i-1] + MOD * MOD) % MOD) + get(i-1, k-1) % MOD) ) % MOD;
    }
    else{
        return get(i-1, k) % MOD;
    }
}

void solve(){
    if ( k == 0 ) {cout << 0; return;}
    cout << get(numbit, k);
}

int main(){
    init();
    solve();
    return 0;
}
