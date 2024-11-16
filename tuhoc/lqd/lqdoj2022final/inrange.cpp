#include<bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;

int n, A, B, P, MOD;

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

namespace sub1{
    pi a[1005];
    ll ans = 0;
    int f[1005];

    void solve(){
        a[1].fi = A, a[1].se = B;
        f[1] = 0;
        for (int i = 2; i <= n; i ++){
            a[i].fi = add(a[i-1].fi, add(mul(f[i-1], P), Pow(i + A, A))) + 1;
            a[i].se = add(a[i-1].se, add(mul(f[i-1], P), Pow(i + B, B))) + 1;
            for (int j = 1; j < i; j ++)
                if ( a[j].fi < a[i].fi && a[j].se < a[i].se )
                    f[i] ++;
            ans += f[i];
        }

//        for (int i = 1; i <= n; i ++)
//            cout << a[i].fi << ' ' << a[i].se << '\n';

        cout << ans;
    }
}

namespace sub2{
    int x, y, f;
    ll ans = 0;
    int bit[1003][1003];

    void upd(int x, int y, int v){
        for (int i = x; i <= MOD; i += i&-i)
        for (int j = y; j <= MOD; j += j&-j)
            bit[i][j] += v;
    }

    int get(int x, int y){
        int res = 0;
        for (int i = x; i >= 1; i -= i&-i)
        for (int j = y; j >= 1; j -= j&-j)
            res += bit[i][j];
        return res;
    }

    void solve(){
        x = A, y = B;
        f = 0;
        upd(x, y, 1);
//        cout << x << ' ' << y << '\n';
        for (int i = 2; i <= n; i ++){
            x = add(x, add(mul(f, P), Pow(i + A, A))) + 1;
            y = add(y, add(mul(f, P), Pow(i + B, B))) + 1;
            f = get(x-1, y-1);
//            cout << x << ' ' << y << ' ' << f << '\n';
            ans += f;
            upd(x, y, 1);
        }
        cout << ans;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("inrange.inp", "r", stdin);
    freopen("inrange.out", "w", stdout);

    cin >> n >> A >> B >> P >> MOD;

    if ( n <= 1000 ) { sub1::solve(); return 0; }
    if ( MOD <= 1000 ) { sub2::solve(); return 0; }

    return 0;
}
