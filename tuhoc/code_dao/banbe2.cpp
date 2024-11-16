#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int su[N];

int tu(int n) {
    int sum = 1;
    for (int i = 2; i * i <= n; i ++){
        if (n % i == 0) {
            sum += i;
            if (i != n / i)
                sum += n / i;
        }
    }
    return sum;
}


void sieve(){
    for (int i = 1; i <= N; i ++)
    for (int j = i * 2; j <= N; j += i)
        su[j] += i;
}

int main(){
    long long l, r;
    cin >> l >> r;
//    for (int i = l; i <= r; i ++){
//        su[i] = tu(i);
//        cout << su[i] << ' ' << su[i] << '\n';
//    }

    sieve();

    long long ans = 0;
    for (int i = l; i <= r; i ++){
        if ( su[i] > r || su[i] < l ) continue;
        if ( su[su[i]] == i && su[i] <= i ) ans ++;
    }

    cout << ans;

    return 0;
}
