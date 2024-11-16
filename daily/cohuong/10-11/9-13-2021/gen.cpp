#include<bits/stdc++.h>
#define simon "gen"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const ll MOD = 1e9 + 3;
const int base = 31;

int n;
string s[N];
vector<ll> Hash[N];
int lo, hi, res;

void makeHash(int i){
    ll tmph = 0;
    for (int j = 0; j < s[i].size(); j ++){
        tmph = ( tmph * base + s[i][j] - 'a' + 1 ) % MOD;
        Hash[i].push_back(tmph);
    }
}

bool check(int len){
    map<ll, int> d;
    for (int i = 1; i <= n; i ++){
        if ( len > s[i].size() ) continue;
        ll t = Hash[i][len-1];
        if ( d[t] != 0 ) return false;
        else d[t] = i;
    }
    return true;
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;

    int mxl = 0;
    for (int i = 1; i <= n; i ++){
        cin >> s[i]; int l = s[i].size();
        mxl = max(mxl, l);
        makeHash(i);
    }

    lo = 1, hi = mxl, res = 0;
    while ( lo <= hi ){
        int mid = ( lo + hi ) / 2;
        if ( check(mid) ){
            res = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }

    cout << res;

    return 0;
}
