#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll base = 31;

int n;
string s, t;
ll pw[N], h[N], rh[N];

ll geth(int l, int r){
    return ( h[r] - h[l-1] * pw[r-l+1] + MOD*MOD ) % MOD;
}

ll getrh(int l, int r){
    return ( rh[r] - rh[l-1] * pw[r-l+1] + MOD*MOD ) % MOD;
}

int inv(int x){
    return n-x+1;
}

void solve(){
    cin >> n >> s;
    t = s;
    s = ' ' + s;
    for (int i = 1; i <= n; i ++)
        h[i] = ( h[i-1] * base + s[i] - 'a' + 1 ) % MOD;

    reverse(t.begin(), t.end());
    t = ' ' + t;
    for (int i = 1; i <= n; i ++)
        rh[i] = ( rh[i-1] * base + t[i] - 'a' + 1 ) % MOD;

    vector<int> ans;
    for (int i = 1; i <= n; i ++){
//        cout << i << " : \n";
        if ( i-1 < n-i ){
            int rem = n-i-(i-1);
//            cout << "here " << h[i-1] << ' ' << rh[i-1] << " and " << i+1 << "->" << i+rem << '\n' ;
            if ( h[i-1] == rh[i-1] && geth(i+1, i+rem) == getrh(inv(i+rem), inv(i+1)) ){
                ans.pb(i);
//                cout << "pick\n";
            }
        }
        else{
//            cout << h[n-i] << ' ' << rh[n-i] << " and " << n-i+1 << "->" << i-1 << '\n';
            if ( h[n-i] == rh[n-i] && geth(n-i+1, i-1) == getrh(inv(i-1), inv(n-i+1)) ){
                ans.pb(i);
//                cout << "pick\n";
            }
        }
    }

    cout << ans.size() << '\n';
    for (int x : ans) cout << x-1 << ' ';
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("trochoi.inp", "r", stdin);
    freopen("trochoi.out", "w", stdout);

    pw[0] = 1;
    for (int i = 1; i < N; i ++)
        pw[i] = pw[i-1] * base % MOD;

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
