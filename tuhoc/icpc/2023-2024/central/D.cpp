#include <bits/stdc++.h>
#define f(i,a,b) for(int i = a;i <= b;++i)
//#define int long long
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

string c[maxn];

bool check(int range) {
    int cnt = 0;
    f(i , 1 , n) {
        int remain = 0;
        f(j,1,m) {
            if (c[i][j] == '#') {
                remain = 0;
            }else {
                if (c[i][j] == 'x') {
                    if (remain == 0) {
                        cnt++;
                        remain = range * 2 + 1;
                    }
                }
                remain--;
                maximize(remain , 0);
            }
        }
    }
    return cnt <= k;
}

void process() {
    cin >> n >> m >> k;
    f(i,1,n) {
        cin >> c[i];
        c[i] = " " + c[i];
    }
//    cout << check(1);return;
    int l = -1 , r = maxn;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;else l = mid;
    }
    cout << (r == maxn ? -1 : r);
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
