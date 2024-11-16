#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 5;

int n;
ll X, a[N], pre[N], spre[N], suf[N], ssuf[N];
pi ansp[N], anss[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> X;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = n + 1; i <= 2 * n - 1; i ++)
        a[i] = a[i-n];

    for (int i = 1; i <= 2 * n - 1; i ++){
        pre[i] = pre[i-1] + a[i];
        spre[i] = spre[i-1] + pre[i];
    }

    for (int i = 2 * n - 1; i >= 1; i --){
        suf[i] = suf[i+1] + a[i];
        ssuf[i] = ssuf[i+1] + suf[i];
    }

    int ptr = 0;
    ll cnt = 0, sum = 0;
    for (int i = 1; i <= 2 * n - 1; i ++){
        while ( ptr < i && pre[i] - pre[ptr] > X ) ptr ++;

        int j = max(i - n, ptr);
        ansp[i] = {i - j, pre[i] * (i - j) - (spre[i-1] - ( !j ? 0 : spre[j-1]))};

        if ( i <= n )
            cnt += ansp[i].fi, sum += ansp[i].se;
    }

    ptr = 2 * n;
    for (int i = 2 * n - 1; i >= 1; i --){
        while ( ptr > i && suf[i] - suf[ptr] > X ) ptr --;

        int j = min(i + n, ptr);
//        cout << i << ' ' << j << '\n';
        anss[i] = {j - i, suf[i] * (j - i) - (ssuf[i+1] - ssuf[j+1])};
    }

//    cout << sum << ' ' << cnt << '\n';
    for (int i = 1; i < n; i ++){
        cnt -= anss[i].fi, sum -= anss[i].se;
        cnt += ansp[n+i].fi, sum += ansp[n+i].se;
        cout << sum << ' ' << cnt << '\n';
    }

    return 0;
}
