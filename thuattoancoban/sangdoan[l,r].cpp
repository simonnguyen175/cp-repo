#include <bits/stdc++.h>
using namespace std;

int R, L;

int main(){
    cin >> L >> R;
    vector<bool> isPrime(R - L + 1, true);
    for (long long i = 2; i * i <= R; ++i) {
        for (long long j = max(i * i, (L + i - 1)/ i * i ); j <= R; j += i) {
            isPrime[j - L] = false;
        }
    }

    if (1 >= L) {  // Xét riêng trường hợp số 1
        isPrime[1 - L] = false;
    }

    for (long long x = L; x <= R; ++x) {
        if (isPrime[x - L]) {
            // i là số nguyên tố
            cout << x <<'\n';
        }
    }
    return 0;
}
