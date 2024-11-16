#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
const ll oo = 1e15;

int n;
int a[N];
ll mnu[N], mnd[N], fu[N], fd[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 1; i <= n; i ++)
        fu[i] = fd[i] = -oo;

    mnu[1] = a[1];
    mnu[2] = a[1] + a[2];
    mnu[3] = min(a[1] + a[2] + a[3], 0);
    fu[3] = a[1] + a[2] + a[3];
    ll s = a[1] + a[2] + a[3];

    for (int i = 4; i <= n; i ++){
        s += a[i];
        fu[i] = max(fu[i-1], s - mnu[i-3]);
        mnu[i] = min(mnu[i-3], s);
    }

    mnd[n] = a[n];
    mnd[n-1] = a[n] + a[n-1];
    mnd[n-2] = min(a[n] + a[n-1] + a[n-2], 0);
    fd[n-2] = a[n] + a[n-1] + a[n-2];
    s = a[n] + a[n-1] + a[n-2];

    for (int i = n-3; i >= 1; i --){
        s += a[i];
        fd[i] = max(fd[i+1], s - mnd[i+3]);
        mnd[i] = min(mnd[i+3], s);
    }

    ll ans = -oo;
    for (int i = 3; i <= n-3; i ++)
        ans = max(fu[i] + fd[i+1], ans);

    cout << ans;

    return 0;
}
