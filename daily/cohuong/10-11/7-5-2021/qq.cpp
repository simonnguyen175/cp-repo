#include<bits/stdc++.h>
#define simon "qq"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e5 + 5;

int n, x[N], y[N];

void file(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
}

int main(){
    file();
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> x[i] >> y[i];

    long long ans;
    sort(x+1, x+1+n);
    sort(y+1, y+1+n);

    // chuyen ve 1 hang
    long long res = 0;
    int med = x[(1+n)/2];
    for (int i = 1; i <= n; i ++)
        res += abs(x[i]-med);
    med = y[(1+n)/2] - (1+n)/2 + 1;
    for (int i = 1; i <= n; i ++)
        res += abs(y[i]-i+1-med);
    ans = res;

    // chuyen ve 1 cot
    res = 0;
    med = y[(1+n)/2];
    for (int i = 1; i <= n; i ++)
        res += abs(y[i]-med);
    med = x[(1+n)/2] - (1+n)/2 + 1;
    for (int i = 1; i <= n; i ++)
        res += abs(x[i]-i+1-med);
    ans = min(ans, res);

    cout << ans;

    return 0;
}
