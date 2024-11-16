#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;

int t, f[N];
bool isPrime[N];

void init(){
    memset(isPrime, 1, sizeof isPrime);
    isPrime[1] = 0;
    for (int i = 2; i * i <= N; i ++)
        if ( isPrime[i] )
            for (int j = i * i; j <= N; j += i)
                isPrime[j] = 0;

    for (int i = 1; i * i <= N; i ++)
        for (int j = 1; j * j * j * j <= N; j ++){
            int sum = i * i + j * j * j * j;
            if ( sum <= N && isPrime[sum] ) f[sum] = 1;
        }

    for (int i = 1; i <= N; i ++)
        f[i] += f[i-1];
}


int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    init();
    cin >> t;
    while ( t -- ){
        int n;
        cin >> n;
        cout << f[n] << '\n';
    }
}
