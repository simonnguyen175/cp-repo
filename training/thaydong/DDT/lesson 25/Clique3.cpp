#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define ll long long
using namespace std;
const int N = 3e6 + 5;

int n;
int db[N], du[N], d[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1, x; i <= n; i ++){
        cin >> x;
        d[x] = i;
    }

    ll ans = 0;
    for (int i = 1; i < N; i ++) if ( d[i] ){
        for (int j = 2*i; j < N; j += i) if ( d[j] ){
            db[i] ++;
            du[j] ++;
        }
        ans += 1LL * du[i] * db[i];
    }

    cout << ans;

    return 0;
}
