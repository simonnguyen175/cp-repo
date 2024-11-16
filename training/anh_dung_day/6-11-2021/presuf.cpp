#include<bits/stdc++.h>
#define simon "presuf"
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll base = 31;

string s;
int n;
ll Hash[N], Pow[N], t[N];
bool xx[N];

ll getHash(int i, int j){
    return ( Hash[j] - Hash[i-1] * Pow[j-i+1] + MOD * MOD ) % MOD;
}

void init(){
    cin >> s;
    n = s.size();
    s = ' ' + s;

    Pow[0] = 1;
    for (int i = 1; i <= n; i ++)
        Pow[i] = ( Pow[i-1] * base ) % MOD;
    for (int i = 1; i <= n; i ++)
        Hash[i] = ( Hash[i-1] * base + s[i] - 'A' + 1 ) % MOD;
}

void solve(){
    for (int i = 1; i <= n; i ++){
        int d = 1, c = n - i + 1, res = 0;

        while ( d <= c ){
            int mid = ( d + c ) / 2;
            if ( getHash(1, mid) == getHash(i, i + mid - 1) ){
                res = mid;
                d = mid + 1;
            }
            else c = mid - 1;
        }

        if ( res == 0 ) continue;
        t[1] ++; t[res + 1] --;
    }

    for (int i = 2; i <= n; i ++)
        t[i] += t[i-1];
    int cnt = 0;
    for (int i = 1; i <= n; i ++)
        if ( getHash(1, i) == getHash(n - i + 1, n) ) xx[i] = 1, cnt ++;
    cout << cnt << '\n'; for (int i = 1; i <= n; i ++) if ( xx[i] ) cout << i << ' ' << t[i] << '\n';
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    init();
    solve();
    return 0;
}
