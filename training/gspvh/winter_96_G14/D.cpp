#include<bits/stdc++.h>
#define ll long long
#define simon "photos"
#define BIT(x, k) ((x>>k)&1)
using namespace std;
const int N = 1e5 + 5;
const int MOD = 998244353;

int n, inv2;
ll m;
int a[N];
vector<int> cont;
int cnt[32][2][N];
int pw2[32];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

int Pow(int a, int b){
    if ( b == 0 ) return 1;
    int tmp = Pow(a, b/2);
    if ( b % 2 ) return mul(tmp, mul(tmp, a));
    else return mul(tmp, tmp);
}

ll getcnt(int pre, int pos){
    ll res = 0;
    for (int i = 1; i <= n; i ++){
        int t = pre ^ a[i];
        t >>= pos;
        t <<= pos;

        /// doan l..r chua pre = t
        int l, r;
        int lo = 1, hi = n, p = -1;
        while ( lo <= hi ){
            int mid = lo + hi >> 1;
            if ( a[mid] >= t ) p = mid, hi = mid - 1;
            else lo = mid + 1;
        }
        if ( p == -1 ) continue;
        l = p;
        lo = 1, hi = n, p = -1;
        while ( lo <= hi ){
            int mid = lo + hi >> 1;
            if ( a[mid] <= t + (1<<pos) - 1 ) p = mid, lo = mid + 1;
            else hi = mid - 1;
        }
        if ( p == -1 ) continue;
        r = p;

        res += r - l + 1;
    }
    return res/2;
}

int getsum(int pre, int pos){
    int res = 0;
    for (int i = 1; i <= n; i ++){
        int t = pre ^ a[i];
        t >>= pos;
        t <<= pos;

        /// doan l..r chua pre = t
        int l, r;
        int lo = 1, hi = n, p = -1;
        while ( lo <= hi ){
            int mid = lo + hi >> 1;
            if ( a[mid] >= t ) p = mid, hi = mid - 1;
            else lo = mid + 1;
        }
        if ( p == -1 ) continue;
        l = p;
        lo = 1, hi = n, p = -1;
        while ( lo <= hi ){
            int mid = lo + hi >> 1;
            if ( a[mid] <= t + (1<<pos) - 1 ) p = mid, lo = mid + 1;
            else hi = mid - 1;
        }
        if ( p == -1 ) continue;
        r = p;

        res = add(res, mul(pre, r-l+1));
        for (int j = pos - 1; j >= 0; j --){
            if ( BIT(a[i], j) )
                res = add(res, mul(pw2[j], cnt[j][0][r]-cnt[j][0][l-1]));
            else res = add(res, mul(pw2[j], cnt[j][1][r]-cnt[j][1][l-1]));
        }
    }

    return mul(res, inv2);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

//    if ( fopen(simon".inp", "r") ){
//        freopen(simon".inp", "r", stdin);
//        freopen(simon".out", "w", stdout);
//    }

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i ++)
    for (int j = 0; j <= 30; j ++){
        cnt[j][0][i] = cnt[j][0][i-1];
        cnt[j][1][i] = cnt[j][1][i-1];
        if ( BIT(a[i], j) ) cnt[j][1][i] ++;
        else cnt[j][0][i] ++;
    }

    pw2[0] = 1;
    for (int i = 1; i <= 30; i ++)
        pw2[i] = mul(pw2[i-1], 2);
    inv2 = Pow(2, MOD-2);

    int cur = 0;
    int ans = 0;

    for (int i = 30; i >= 0; i --){
        ll tmp = getcnt((cur|(1<<i)), i);
//        cout << i << ' ' << cur << ' ' << tmp << '\n';
        if ( tmp < m ){
            ans = add(ans, getsum((cur|(1<<i)), i));
            m -= tmp;
        }
        else cur |= (1<<i);
    }
    ans = add(ans, mul(cur, m));
    cout << ans;

    return 0;
}
