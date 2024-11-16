#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll base = 31;

unordered_map<int, int> d, e;
int n, m;
pair<int, string> a[N];
ll HashL[N], HashR[N], Pow[N], ans = 0;

ll getHash(ll Hash[], int i, int j){
    return ( Hash[j] - Hash[i-1] * Pow[j-i+1] + MOD * MOD ) % MOD;
}

bool checkPalin(int l, int r){
    if ( l > r ) return false;
    return getHash(HashL, l, r) == getHash(HashR, m - r + 1, m - l + 1);
}

void incHash(int p){
    m = a[p].first;
    string s = a[p].second;s = ' ' + s;
    ll HashS = 0;
    for (int i = 1; i <= m; i ++)
        HashS = ( HashS * base + s[i] - 'a' + 1 ) % MOD;
    d[HashS] ++;
}

void anal(int p){
    m = a[p].first;
    string s = a[p].second, t = s;
    reverse(t.begin(), t.end());
    s = ' ' + s; t = ' ' + t;

    for (int i = 0; i <= m; i ++)
        HashL[i] = HashR[i] = 0;

    for (int i = 1; i <= m; i ++){
        HashL[i] = ( HashL[i-1] * base + s[i] - 'a' + 1 ) % MOD;
        HashR[i] = ( HashR[i-1] * base + t[i] - 'a' + 1 ) % MOD;
    }

    // truong hop hai xau bang nhau
    ans += d[HashR[m]];

    for (int i = 1; i <= m; i ++){
        // truong hop xet day la xau ghep ben trai
        if ( checkPalin(i + 1, m) ) ans += d[getHash(HashR, m - i + 1, m)];

        // truong hop xet day la xau ghep ben phai
        if ( checkPalin(1, m - i) ) ans += d[HashR[i]];
    }
}

void solve(){
    sort(a + 1, a + 1 + n);

    Pow[0] = 1;

    for (int i = 1; i <= 1e6; i ++)
        Pow[i] = ( Pow[i-1] * base ) % MOD;

    for (int i = 1; i <= n; i ++)
        incHash(i);

    for (int i = 1; i <= n; i ++)
        anal(i);

    cout << ans;
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
    cin >> n;

    for (int i = 1; i <= n; i ++)
        cin >> a[i].first >> a[i].second;

    solve();

    return 0;
}
