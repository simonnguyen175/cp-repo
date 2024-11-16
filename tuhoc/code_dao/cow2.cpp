#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define N 1000003
#define endl '\n'
using namespace std;

ull dp[N];
ll a[N];
ll b[N];

bool check(ll mid, ll c, ll n) {
    ll s = 1;
    ll q = a[1];
    // xep nhung con bo cang gan ve phia dau cang tot ma thoa man dieu kien cach nhau >= mid
    for (ll i = 2;i<=n;i++) {
        if ( a[i]-q>=mid ){
            q = a[i];
            s ++;
        }
    }
    return s >= c;
}

ll BS(ll n, ll c){ // chat khoang cach nho nhat giua hai con bo
    // thi don vi dang chat la khoang cach
    // can lon nhat cua khoang cach la c[n] - c[1]
    ll l = 1, r = a[n] - a[1], ans;

    // l la can nho nhat cua ket qua
    // r la can lon nhat cua ket qua
    while ( l <= r ){
        ll mid = (l + r) / 2;
        if ( check(mid, c, n) ){
            l = mid + 1;
            ans = mid;
        }
        else{
            r = mid - 1;
        }
    }

    return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, c;
    cin >> n >> c;
    for(ll i = 1; i <= n; i ++) cin >> a[i];
    sort(a + 1, a + 1 + n);
//    cout << check(3, c, n) << '\n';
    // chat ket qua la khoang cach nho nhat cua 2 con bo
    // ta chat sao cho tim duoc khoang cach nho nhat day la lon nhat co the
    cout << BS(n, c);

    return 0;
}
