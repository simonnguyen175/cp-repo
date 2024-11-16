#include<bits/stdc++.h>
using namespace std;
const int MOD = 939999953;

int n;

int main(){
    cin >> n;
    if ( n >= 2e7 ) cout << 0;
    else{
        if ( n < 2 ) {cout << 1; return 0;}
        long long lt1 = 1, lt2 = 1;
        for (int i = 1; i <= n; ++i) {
            if (i < n) lt1 = (lt1 * i) % MOD;
            if (i != 2) lt2 = (lt2 * i) % MOD;
        }
        cout << (lt1 * lt2) % MOD;
    }
    return 0;
}
