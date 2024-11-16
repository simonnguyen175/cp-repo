#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll base = 79;

int n;
string t, s;
ll Pow[N], HashS[N], HashT[N];

ll getHash(ll Hash[], int i, int j){
    return ( Hash[j] - Hash[i-1] * Pow[j-i+1] + MOD * MOD ) % MOD;
}

void anal(){
    int m = t.size(), len = s.size() - 1;
    t = ' ' + t;
    HashT[0] = 0;
    for (int i = 1; i <= m; i ++)
        HashT[i] = ( HashT[i-1] * base + t[i] - '0' + 1 ) % MOD;

    int add = 0;

    for (int i = min(len, m); i >= 1; i --)
        if ( getHash(HashT, 1, i) == getHash(HashS, len - i + 1, len) ){
            add = i;
            break;
        }

    for (int i = add + 1; i <= m; i ++){
        len ++;
        HashS[len] = ( HashS[len-1] * base + t[i] - '0' + 1 ) % MOD;
        s += t[i];
    }
}

void solve(){
    cin >> n;

    Pow[0] = 1;
    for (int i = 1; i <= N; i ++)
        Pow[i] = ( Pow[i-1] * base ) % MOD;

    s = ' ';
    cin >> t; s += t;
    for (int i = 0; i < t.size(); i ++)
        HashS[i+1] = ( HashS[i] * base + t[i] - '0' + 1 ) % MOD;

    for (int i = 2; i <= n; i ++){
        cin >> t;
        anal();
    }

    s = s.substr(1, s.size()-1);
    cout << s;
}

int main(){
    solve();
    return 0;
}
