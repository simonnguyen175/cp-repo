#include <bits/stdc++.h>
using namespace std;
int tuoc(int n) {
    int sum = 1;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i)
                sum += n / i;
        }
    }
    return sum;
}
int main() {
    int  L, R;
    cin >> L >> R;
    long long count = 0;
    for (int a = L; a <= R; ++a) {
        for (int b = a; b <= R; ++b) {
            if (tuoc(a) == b && tuoc(b) == a) {
                count++;
                cout << a << ' ' << b << '\n';
            }
        }
    }

    cout << count;
}
