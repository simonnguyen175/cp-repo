#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int N = 1e3 + 5;
const int MOD = 111539786;

int t;
pair<char, ll> a[N];
ll f[N], Next[N][30];

void solve(string s){
    // anal s
    a[0].fi = '#', a[0].se = 1;
    char ch = s[0]; int n = 0; ll cnt = 0;

    for (int i = 1; i < s.size(); i ++)
        if ( s[i] >= '0' && s[i] <= '9' )
            cnt = (cnt * 10 + (int)(s[i] - '0'))%MOD;
        else{
            a[++n] = {ch, cnt};
            ch = s[i];
            cnt = 0;
        }

    a[++n] = {ch, cnt};

    /*
    for (int i = 0; i <= n; i ++)
        cout << '(' << a[i].fi << ',' << a[i].se << ')' << ' ';
    cout<<'\n';
    */

    memset(f, 0, sizeof f);
    memset(Next, -1, sizeof Next);

    for (int i = n; i >= 1; i --){
        for (int c = 0; c <= 25; c ++) Next[i-1][c] = Next[i][c];
        Next[i-1][a[i].fi - 'a'] = i;
            //cout << "Next["<<i-1<<"]["<<a[i].fi<<"] = " << Next[i-1][a[i].fi - 'a'] << '\n';
    }

    ll ans = 0; f[0] = 1;

    for (int i = 0; i <= n; i ++){
        ans = (ans + (f[i]*a[i].se)%MOD) % MOD;

        for (int c = 0; c <= 25; c ++){
            int j = Next[i][c];

            if ( j == -1 ) continue;

            if ( c == a[i].fi - 'a' ) f[j] = ( f[j] + f[i] ) % MOD;
            else f[j] = ( f[j] + (a[i].se*f[i])%MOD ) % MOD;
        }
    }

    cout << ( ans - 1 + MOD ) % MOD << '\n';
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    freopen("d13rlesubstr.inp", "r", stdin);
    freopen("d13rlesubstr.out", "w", stdout);

    cin >> t;
    while ( t -- ){
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}
