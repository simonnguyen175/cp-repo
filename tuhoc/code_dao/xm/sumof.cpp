#include<bits/stdc++.h>
using namespace std;

bool cp(long long x){
    long long tmp = sqrt(x);
    return tmp * tmp == x;
}

int main(){
    ios::sync_with_stdio();
    cin.tie(0);cout.tie(0);

    freopen("sumof.inp", "r", stdin);
    freopen("sumof.out", "w", stdout);

    int n;
    cin >> n;
    int ans = 0;
    for (long long i = 1; i <= sqrt(n/3) + 5; i ++)
    for (long long j = i; j <= sqrt(n); j ++) if ( i*i + j*j < n && cp(n - i*i - j*j) &&  sqrt(n - i*i - j*j) >= j )
        ans ++;

    cout << ans << '\n';

    return 0;
}

