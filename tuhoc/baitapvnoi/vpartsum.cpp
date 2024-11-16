
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;

int n, p, k, cnt;
int a[N], s[N], c[N], bit[N];

void init(){
    cin >> n >> k >> p;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++){
        s[i] = ( s[i-1] + a[i] ) % p;
        c[i] = s[i];
    }
    s[++n] = 0; c[n] = s[n];

    sort(c + 1, c + 1 + n);
    cnt = 1;
    for (int i = 2; i <= n; i ++)
        if ( c[i] > c[cnt] ) c[++cnt] = c[i];
}

void update(int u, int v){
    int idx = u;
    while ( idx <= cnt ){
        bit[idx] = max(bit[idx], v);
        idx += idx & (-idx);
    }
}

int get(int u){
    int idx = u, res = INT_MIN;
    while ( idx > 0 ){
        res = max(res, bit[idx]);
        idx -= idx & (-idx);
    }
    return res;
}

int tknp(int u){
    int l = 1, r = cnt, res = 0;
    while ( l <= r ){
        int mid = ( l + r ) / 2;
        if ( c[mid] <= u ){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    return res;
}

void solve(){
    int ans = INT_MAX, u;

    for (int i = 1; i <= n; i ++){
        if ( s[i] >= k ){
            u = tknp(s[i] - k);
            ans = min(ans, s[i] - get(u));
        }

        u = tknp(s[i] + p - k);
        int tmp = get(u);
        if ( tmp >= s[i] ) ans = min(ans, s[i] - tmp + p);

        u = tknp(s[i]);
        update(u, s[i]);
    }

    cout << ans;
}

int main(){
    init();
    solve();
    return 0;
}
