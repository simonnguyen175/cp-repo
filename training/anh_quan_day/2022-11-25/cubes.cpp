#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;

int w, d;
int a[N], b[N];
map<int, int> da, db;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> w >> d;
    for (int i = 1; i <= w; i ++) cin >> a[i], da[a[i]] ++;
    for (int i = 1; i <= d; i ++) cin >> b[i], db[b[i]] ++;

    ll ans = 0;
    for (int i = 1; i <= 1000; i ++)
        ans += 1ll * i * max(da[i], db[i]);

    cout << ans;

    return 0;
}
