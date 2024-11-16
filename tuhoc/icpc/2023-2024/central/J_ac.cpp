#include <bits/stdc++.h>
#define f(i,a,b) for(int i = a;i <= b;++i)
#define int long long
#define ll long long
#define pii pair<int,int>
#define piii pair<int , pii>
#define piiii pair <pii , pii>
#define F first
#define S second
#define task "nhuhieu193"
#define mod 1000000007
#define endl '\n'
#define minimize(x,y) x = (x > y ? y : x)
#define maximize(x,y) x = (x < y ? y : x)
using namespace std;
const int maxn = 100005;

int gcd(int x , int y) {
    return y ? gcd(y , x % y) : x;
}

string Y = "YES\n" , N = "NO\n" , Al = "Alice\n" , Bo = "Bob\n";

ll POWW(ll t , ll x) {
    if (x == 0) return 1;
    ll B = POWW(t , x / 2);
    ll C = B * B % mod;
    if (x & 1) C = C * t % mod;
    return C;
}

int n,m,k;

/// Author : CBN_K28_nhuhieu193

/// welcome to my amazing code !!!

string s;

int type = -1;
char res[maxn];
int a[maxn] , b[maxn];

void calc1(int c) {
    int cnt = 0;
    f(i,0,n-1) cnt += (res[i] == 'R');

    for (int i = n - 1; i >= 0 && cnt > c; i--) {
        cnt-=(res[i] == 'R');
        res[i] = 'B';
    }
      for (int i = n - 1; i >= 0 && cnt < c; --i) {
        cnt += (res[i] == 'B');
        res[i] = 'R';
      }
}

int calc(int cnt) {
    if (type == -1) f(i,0,n - 1) res[i] = s[i % m]; else {
        for (int i = m - 1 ; i >= 0 ; i--) res[i] = s[i];
        f(i,m,n-1) res[i] = res[i - type];

    }
    calc1(cnt);
        ll ans = 0;
          f(i,0,n-m) {
            bool ok = 1;
            f(j,0,m-1)
              if (res[i + j] != s[j]) {ok = 0;break;}
            ans += ok;
          }
        return ans * k;
}

void solve1(int nums) {
    calc(nums);
    f(i,0,n - 1) cout << res[i];
}

void solve() {
    int nums = -1e9;
    ll ans = -2e9;
    f(i,0,n) {
        ll tmp = calc(i) - a[i] - b[n - i];
        if (ans < tmp) {
            ans = tmp;
            nums = i;
        }
    }
    cout << ans << '\n';
    solve1(nums);
}


void process() {
    cin >> n >> m >> k;
    f(i,1,n) cin >> a[i];
    f(i,1,n) cin >> b[i];
    cin >> s;
    for (int leng = m - 1 ; leng >= 1 ; leng--) {
        bool check = 1;
        for (int j = m - 1 ; j >= leng ; j--) {
            if (s[j - leng] != s[j]) {check = 0; break;}
        }
        if (check) {
            type = leng;
        }
    }
    solve();
}

/// This is end of my solution.

int32_t main() {
    ios_base::sync_with_stdio(false);
//    freopen(task".inp","r",stdin);
//    freopen(task".out","w",stdout);
    cin.tie(0);
    int ntest = 1;
//    cin >> ntest;
    while (ntest--) {
        process();
    }

}
/// range maxn , memory
/// long long , mod
/// implement
/// file
/// reset testcase
