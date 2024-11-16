#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;

int n, q;
pair<int, int> a[N], x[N];
long long ans[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].se >> a[i].fi;
    }
    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= q; i ++)
        cin >> x[i].fi, x[i].se = i;
    sort(x + 1, x + 1 + q);

    int j = 1;
    long long time = 0;
    for (int i = 1; i <= q; i ++){
        while ( a[j].fi <= x[i].fi && j <= n ){
            time += a[j].se;
            j ++;
        }
        ans[x[i].se] = time;
    }

    for (int i = 1; i <= q; i ++)
        cout << ans[i] << '\n';

    return 0;
}
