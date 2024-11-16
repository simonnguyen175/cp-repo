#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e4 + 5;
const ll MOD = 1e9 + 7;
const ll base = 271;

int n, k;
string s;
ll Hash[N], Pow[N];

ll getHash(int i, int j){
    return ( Hash[j] - Hash[i-1] * Pow[j - i + 1] + MOD * MOD ) % MOD;
}

void makeHash(){
    s = ' ' + s;
    Pow[0] = 1;
    for (int i = 1; i <= n; i ++)
        Pow[i] = ( Pow[i-1] * base ) % MOD;

    for (int i = 1; i <= n; i ++)
        Hash[i] = ( Hash[i-1] * base + s[i] - 'a' + 1 ) % MOD;
}


bool check(int l){
    vector<ll> strl; strl.clear();

    for (int i = 1; i <= n - l + 1; i ++){
        strl.push_back(getHash(i, i + l - 1));
    }

    sort(strl.begin(), strl.end());

    int cnt = 1;

    for (int i = 1; i < strl.size(); i ++)
        if ( strl[i] == strl[i-1] ) cnt ++;
        else{
            if ( cnt >= k ) return true;
            cnt = 1;
        }

    if ( cnt >= k ) return true;

    return false;
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n >> k >> s;
    makeHash();

    int d = 1, c = n, res;
    while ( d <= c ){
        int mid = ( d + c ) / 2;
        if ( check(mid) ){
            res = mid;
            d = mid + 1;
        }
        else c = mid - 1;
    }

    cout << res;

    return 0;
}
