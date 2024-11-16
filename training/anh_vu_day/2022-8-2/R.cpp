#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const int base =  31;
const ll MOD = 1e9 + 7;

int n, m;
string s, t;
ll pw[N], Hash[N], hasht[N], d[N];
int p[N];
ll ans = 0;

ll get(int l, int r){
    return ( Hash[r] - Hash[l-1] * pw[r-l+1] + MOD * MOD ) % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> s >> t;
    n = s.size();
    m = t.size();
    s = ' ' + s;
    t = ' ' + t;

    // build t
    for (int i = 1; i <= m; i ++)
        hasht[i] = ( hasht[i-1] * base + t[i] - 'a' + 1 ) % MOD;
    p[1] = 0;
    int k = 0;
    for (int i = 2; i <= m; i ++){
        while ( k && t[k+1] != t[i] ) k = p[k];
        if ( t[k+1] == t[i] ) k ++;
        p[i] = k;
    }
    for (int i = 1; i <= m; i ++) cout << p[i] << '\n';
    for (int i = 1                                                            ; i <= m; i ++)
        d[i - p[i] + 1] ++;
    for (int i = m; i >= 0; i --)
        d[i] += d[i+1];

    // build s
    pw[0] = 1;
    for (int i = 1; i <= n; i ++)
        pw[i] = pw[i-1] * base % MOD;
    for (int i = 1; i <= n; i ++)
        Hash[i] = ( Hash[i-1] * base + s[i] - 'a' + 1 ) % MOD;

    for (int i = 1; i <= n; i ++){
        int lo = i + 1, hi = n, res = i;
        while ( lo <= hi ){
            int mid = lo + hi >> 1;
            if ( get(i+1, mid) == hasht[mid-i] ) res = mid, lo = mid + 1;
            else hi = mid - 1;
        }
        cout << i << ' ' << res-i+1 << ' ' << d[res-i+1] << '\n';
        ans += d[res-i+1];
    }

    cout << ans;

    return 0;
}
