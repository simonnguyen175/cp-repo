#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 5;

int n;
int prime[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    for (int i = 2; i <= N-5; i ++)
        prime[i] = 1;

    for (int i = 2; i * i <= N-5; i ++) if ( prime[i] )
    for (int j = i * i; j <= N-5; j += i)
        prime[j] = 0;

    for (int i = 1; i <= N-5; i ++)
        prime[i] += prime[i-1];

    int test;
    cin >> test;
    while ( test -- ){
        cin >> n;
        ll ans = 0;
        for (int i = 1; i <= n; i ++){
            int blu = prime[i+n] - prime[i];
            if ( i == 1 ) blu --;
            int yel = n - 1 - blu;
            ans += 1ll * blu * yel;
        }

        ans = 1ll * n * (n - 1) * (n - 2) / 6 - ans / 2;

        cout << ans << '\n';
    }

    return 0;
}
