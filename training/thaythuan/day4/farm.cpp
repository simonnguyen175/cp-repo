#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 1;

int n, k, q, p, ans;
int a[N], f[12][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k >> q >> p;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    p = min(p, q);

    for (int i = 1; i <= k; i ++)
    for (int j = 0; j <= p; j ++){
        f[i%12][j] = a[i] * j;
        ans = max(ans, f[i%12][j]);
    }

    for (int i = k+1; i <= n; i ++){
        for (int j = 0; j <= q; j ++)
            f[(i-k+12)%12][j] = max(f[(i-k+12)%12][j], f[(i-k-1+12)%12][j]);
        deque<int> dq;
        for (int j = 0; j <= q; j ++){
            while ( dq.size() && f[(i-k+12)%12][dq.back()] - dq.back()*a[i] < f[(i-k+12)%12][j] - j*a[i] ) dq.pop_back();
            while ( dq.size() && dq.front() < j-p ) dq.pop_front();
            dq.push_back(j);
            if ( dq.size() ) f[i%12][j] = f[(i-k+12)%12][dq.front()] + (j-dq.front())*a[i];
            ans = max(ans, f[i%12][j]);
        }
    }

    cout << ans;

    return 0;
}
