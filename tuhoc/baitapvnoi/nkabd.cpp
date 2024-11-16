#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int l, r;
long long f[N];

int main(){
    for (int i = 1; i <= N; i ++)
        for (int j = i * 2; j <= N; j += i)
            f[j] += i;

    cin >> l >> r;
    int ans = 0;
    for (int i = l; i <= r; i ++)
        if ( f[i] > i ) ans ++;
    cout << ans;
    return 0;
}
