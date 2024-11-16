#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const ll base = 123456789101112;

int n;
ll a[N], b[N];
map<ll, ll> id, d;
ll g = 0, ans = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i] >> b[i];
        id[a[i]] = a[i] + base;
        id[b[i]+1] = b[i] + 1 + base;
    }

    d[0] ++;
    for (int i = 1; i <= n; i ++){
        g ^= id[a[i]] ^ id[b[i]+1];
        ans += d[g];
        d[g] ++;
    }

    cout << ans;

    return 0;
}
