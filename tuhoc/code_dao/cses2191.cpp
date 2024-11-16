#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
struct Point{
    ll x, y;
    ll operator % (const Point &a) { return x * a.y - y * a.x; }
} p[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i ++)
        cin >> p[i].x >> p[i].y;
    p[n+1] = p[1];

    ll ans = 0;
    for (int i = 1; i <= n; i ++)
        ans += p[i] % p[i+1];

    cout << abs(ans);

    return 0;
}
