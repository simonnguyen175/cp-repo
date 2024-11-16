#include<bits/stdc++.h>
#define simon "cc"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int n, k;
long double d[105];

void file(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
}

int main(){
    file();
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> d[i];

    if ( k == 1 ){
        sort(d + 1, d + 1 + n);
        long double med = d[(1+n)/2];
        long double ans = 0;
        for (int i = 1; i <= n; i ++)
            ans += abs(d[i]-med);
        cout << fixed << setprecision(2) << ans;
    }
    else{
        long double p, ans = 0;
        for (int i = 1; i <= n; i ++)
            p += d[i];
        p /= n;
        for (int i = 1; i <= n; i ++)
            ans += (d[i]-p) * (d[i]-p);
        cout << fixed << setprecision(2) << ans;
    }

    return 0;
}
