#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int t, a, b, n;
int primeDiv[N], f[N][11];

void sieve(){
    memset(primeDiv, 0, sizeof primeDiv);
    primeDiv[1] = 0;

    for (int i = 2; i <= N; i ++)
        if ( primeDiv[i] == 0 ){
            for (int j = i; j <= N; j += i)
                primeDiv[j] ++;
        }

    for (int i = 1; i <= N; i ++)
        f[i][primeDiv[i]] = 1;

    for (int i = 1; i <= N; i ++)
        for (int j = 0; j <= 10; j ++)
            f[i][j] += f[i-1][j];
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    sieve();
    cin >> t;
    while ( t -- ){
        cin >> a >> b >> n;
        cout << f[b][n] - f[a-1][n] << '\n';
    }
    return 0;
}
