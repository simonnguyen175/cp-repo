#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 1e3 + 5;

ll k, n = 0;
string s;
pair<char, ll> a[N], b[N];

void init(){
    cin >> k >> s;
    char c = s[0]; ll cnt = 0;
    for (int i = 1; i < s.size(); i ++){
        if ( s[i] >= '0' && s[i] <= '9' )
            cnt = cnt * 10 + (int)(s[i] - '0');
        else{
            a[++n] = {c, cnt};
            c = s[i];
            cnt = 0;
        }
    }
    a[++n] = {c, cnt};
    for (int i = 1; i <= n; i ++) b[i] = a[i];
}

void print(vector<pair<char, ll>> x){
    vector<pair<char, ll>> res;

    for (auto it : x)
        if ( it.se > 0 ){
            if ( !res.size() ) {res.push_back(it); continue;}
            if ( res[res.size()-1].fi == it.fi )
                res[res.size()-1].se += it.se;
            else res.push_back(it);
        }

    for (auto it : res)
        cout << it.fi << it.se;
    cout << '\n';
}

void solve(){
    ll k1 = k;
    stack<pair<char, ll>> stk;

    // MAKE MAX
    for (int i = 1; i <= n; i ++){
        if ( stk.empty() ) { stk.push(a[i]); continue; }

        while ( stk.size() && a[i].fi > stk.top().fi && k > 0 ){
            if ( k - stk.top().se <= 0 ) { stk.top().se -= k; k = 0; }
            else { k -= stk.top().se; stk.pop(); }
        }
        stk.push(a[i]);
    }

    while ( k ){
        if ( stk.top().se < k ) k -= stk.top().se, stk.pop();
        else stk.top().se -= k, k = 0;
    }

    vector<pair<char, ll>> mx;
    while ( stk.size() ) { mx.push_back(stk.top()); stk.pop(); }
    reverse(mx.begin(), mx.end());

    // MAKE MIN
    for (int i = 1; i <= n; i ++){
        if ( stk.empty() ) { stk.push(b[i]); continue; }

        while ( stk.size() && b[i].fi < stk.top().fi && k1 > 0 ){
            if ( k1 - stk.top().se <= 0 ) { stk.top().se -= k1; k1 = 0; }
            else { k1 -= stk.top().se; stk.pop(); }
        }
        stk.push(b[i]);
    }

    while ( k1 ){
        if ( stk.top().se < k1 ) k1 -= stk.top().se, stk.pop();
        else stk.top().se -= k1, k1 = 0;
    }

    vector<pair<char, ll>> mn;
    while ( stk.size() ) { mn.push_back(stk.top()); stk.pop(); }
    reverse(mn.begin(), mn.end());

    print(mx);
    print(mn);
}

int main(){
    if ( fopen("d13reldel.inp", "r") ){
        freopen("d13reldel.inp", "r", stdin);
        freopen("d13reldel.out", "w", stdout);
    }

    init();
    solve();

    return 0;
}
