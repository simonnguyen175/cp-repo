#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;

ll n, L, R;
vector<ll> a;
pi ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("maxdis.inp", "r") ){
        freopen("maxdis.out", "w", stdout);
        freopen("maxdis.inp", "r", stdin);
    }

    cin >> n >> L >> R;
    a.resize(n);
    for (int i = 1; i <= n; i ++)
        cin >> a[i-1];

    sort(a.begin(), a.end());

    if( L == LLONG_MIN && R == LLONG_MAX ){
		if ( a[0] > 0 ) cout << L;
		else cout << R;
		return 0;
	}

    // chon L
    auto it = lower_bound(a.begin(), a.end(), L);
    auto it1 = it --;
    if ( it == a.end() ) ans.fi = abs(L-*it1);
    else ans.fi = min(abs(L-*it1), abs(L-*it));
    ans.se = L;

    // chon R
    it = lower_bound(a.begin(), a.end(), R);
    it1 = it --;
    if ( it == a.end() ){
        if ( ans.fi <= abs(R-*it1) ){
            ans.fi = abs(R-*it1);
            ans.se = R;
        }
    }
    else{
        ll tmp = min(abs(R-*it1), abs(R-*it));
        if ( ans.fi <= tmp ){
            ans.fi = tmp;
            ans.se = R;
        }
    }

    // chon so nam giua 2 so
    for (int i = 0; i < n - 1; i ++){
        ll med = ( ( a[i] + a[i+1] ) % 2 ? ( a[i] + a[i+1] ) / 2 + 1 : ( a[i] + a[i+1] ) / 2 );
        if ( L <= med && med <= R ){
            if ( abs(med - a[i+1]) > ans.fi ){
                ans.fi = abs(med - a[i+1]);
                ans.se = med;
            }
            else if ( abs(med - a[i+1]) == ans.fi && med > ans.se )
                ans.se = med;
        }
    }

    cout << ans.se;

    return 0;
}
