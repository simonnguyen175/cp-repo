#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e6 + 5;
const ll MOD = 1e9 + 7;
const ll base = 271;

int n;
string s;
ll Pow[N], Hash[N];

ll gethash(int i, int j){
    return ( Hash[j] - Hash[i-1] * Pow[j - i + 1] + MOD * MOD ) % MOD;
}

void MakeHash(){
    Pow[0] = 1;
    for (int i = 1; i <= n; i ++)
        Pow[i] = ( Pow[i-1] * base ) % MOD;

    for (int i = 1; i <= n; i ++)
        Hash[i] = ( Hash[i-1] * base + s[i] - 'a' + 1 ) % MOD;
}

bool palin(int i, int j){
    int l = j - i + 1;
    if ( l % 2 == 0 )
        return gethash(i, i + l/2 - 1) == gethash(i + l/2, j);
    else
        return gethash(i, i + l/2 - 1 ) == gethash(i + l/2 + 1, j);
}

bool check(int l){
    for (int i = 1; i <= n - l + 1; i ++)
        if ( palin(i, i + l - 1) ) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> n >> s;
    s = " " + s;
    reverse(s.begin(), s.end());

    MakeHash();

    int ans = 0;

    int d = 1, c = n, res = 0;
    while ( d <= c ){
        int mid = ( d + c ) / 2;
        mid += mid % 2;
        if ( check(mid) ){
            res = mid;
            d = mid + 2;
        }
        else c = mid - 2;
    }
    ans = max(ans, res);

    d = 1, c = n, res = 0;
    while ( d <= c ){
        int mid = ( d + c ) / 2;
        mid += (1 - mid) % 2;
        if ( check(mid) ){
            res = mid;
            d = mid + 2;
        }
        else c = mid - 2;
    }
    ans = max(ans, res);

    cout << ans;

    return 0;
}
