#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int n;
ll a[N], s[N], spalin[N];

int main(){
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }

    long double ans = 0;
    for (int i = 1; i <= n; i ++)
        spalin[i] = spalin[i-1] + i * ( a[i] + a[n-i+1] );

    for (int len = 1; len <= (n+1)/2; len ++){
        int l = len, r = n - len + 1;
        ll tmp = spalin[l-1] + ( s[r] - s[l-1] ) * len;
        ans = ans + tmp * 1.0 / len * 1.0;
    }

    for (int len = (n+1)/2 + 1; len <= n; len ++){
        int l = n - len + 1, r = len;
        ll tmp = spalin[l-1] + ( s[r] - s[l-1] ) * l;
        ans = ans + tmp * 1.0 / len * 1.0;
    }

    ans = ans * 2 / ( n * 1.0 * (n+1) ) ;

    cout << fixed << setprecision(6) << ans;

    return 0;
}
