#include<bits/stdc++.h>
#define simon "aprobot"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fi first
#define se second
using namespace std;
const int N = 5e3 + 5;

int n, k;
pair<int, int> a[N];
int f[N];

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].first; a[i].first *= -1;
        a[i].second = i;
    }

    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i ++)
        if ( i % k ) a[i].fi = i/k + 1;
        else a[i].fi = i/k;

    sort(a + 1, a + 1 + n);

    int ans = 0;

    for (int i = 1; i <= n; i ++)
        for (int j = i - 1; j >= 0; j --){
            if ( a[j].second < a[i].second )
                f[i] = max(f[i], f[j] + 1);
            ans = max(ans, f[i]);
        }

    ans = n - ans;

    cout << ans;

    return 0;
}
