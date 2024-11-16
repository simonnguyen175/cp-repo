#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3 + 5;

int n;
struct info{
    int x, y, z;
} a[6*N];
ll f[6*N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].x >> a[i].y >> a[i].z;
        a[i+n] = {a[i].y, a[i].x, a[i].z};
        a[i+2*n] = {a[i].y, a[i].z, a[i].x};
        a[i+3*n] = {a[i].z, a[i].y, a[i].x};
        a[i+4*n] = {a[i].x, a[i].z, a[i].y};
        a[i+5*n] = {a[i].z, a[i].x, a[i].y};
    }

    n *= 6;
    sort(a+1, a+1+n, [](info b, info c){
        if ( b.x != c.x ) return b.x < c.x;
        else return b.y < c.y;
    });

    f[1] = a[1].z;
    ll ans = 0;
    for (int i = 2; i <= n; i ++){
        f[i] = a[i].z;
        for (int j = i-1; j >= 1; j --)
            if ( a[j].x < a[i].x && a[j].y < a[i].y )
                f[i] = max(f[i], f[j] + a[i].z);
        ans = max(ans, f[i]);
    }

    cout << ans;

    return 0;
}
