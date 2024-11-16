#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;

int n, w, a[N], b[N], c[N], fail[N], ans = 0;

int main(){
    cin >> n >> w;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= w; i ++) cin >> b[i];

    if ( w == 1 ){
        cout << n;
        return 0;
    }

    for (int i = 1; i < n; i ++) a[i] = a[i+1]-a[i], c[i+w] = a[i];
    for (int i = 1; i < w; i ++) b[i] = b[i+1]-b[i], c[i] = b[i];
    c[w] = INT_MAX;

    int m = n + w - 1;

    fail[1] = 0;
    int k = 0;
    for (int i = 2; i <= m; i ++){
        while ( k > 0 && c[k+1] != c[i] ) k = fail[k];
        if ( c[k+1] == c[i] ) k ++;
        fail[i] = k;
        if ( fail[i] == w - 1 ) ans ++;
    }

    cout << ans;
    return 0;
}
