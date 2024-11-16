#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, k;
int a[N], s[N];
long long dp[N], sdp[N];
long long gt[N];

long long mu(long long x, long long y){
    if ( y == 0 ) return 1;
    long long tmp = mu(x, y/2);
    if ( y % 2 == 0 ) return (tmp*tmp)%MOD;
    else return (((tmp*tmp)%MOD)*x)%MOD;
}

long long C(int a, int b){
    if ( b > a ) return 0;
    if ( b == 0 ) return 1;
    return ( gt[a] * mu((gt[a-b]*gt[b])%MOD, MOD-2) )%MOD;
}

void solve(){
    cin >> n >> k;
    int tops = 0;
    for (int i = 1; i <= n; i ++){
        char c;
        cin >> c;
        a[i] = c - '0';
        s[i] = s[i-1] + a[i];
        tops += a[i];
    }

    if ( tops % k != 0 ){
        cout << 0 << '\n';
        return;
    }

//    cout << "co the chia duoc\n";


    if ( tops == 0 ){
        gt[0] = 1;
        for (int i = 1; i < N; i ++)
            gt[i] = (gt[i-1] * i) % MOD;
        cout << C(n-1, k-1) << '\n';
        return;
    }

    for (int i = 0; i <= n; i ++)
        dp[i] = sdp[i] = 0;
    tops /= k;
    dp[0] = sdp[0] = 1;
    int l = 0, r = 0;
    for (int i = 1; i <= n; i ++){
        while ( s[i] - s[r] >= tops && r <= i ){
            r ++;
        }

        while ( s[i] - s[l] >= tops + 1 && l <= i ){
            l ++;
        }

//        cout << i << ' ' << l << ' ' << r << '\n';

        if ( s[i] < tops ) dp[i] = 0;
        else if ( s[i] == tops ) dp[i] = 1;
        else if ( l <= r && r <= i && s[i] - s[l] == tops ){
            dp[i] = (sdp[r-1] - sdp[l-1] + MOD) % MOD;
        }
        sdp[i] = (sdp[i-1] + dp[i]) % MOD;
//        cout << dp[i] << ' ' << sdp[i] << '\n';
    }

    cout << dp[n] << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int test;
    cin >> test;
    while ( test -- ){
        solve();
    }

    return 0;
}
