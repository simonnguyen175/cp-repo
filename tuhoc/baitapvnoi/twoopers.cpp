#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll base = 31;
const ll MOD = 1e9 + 7;
const int N = 1e5 + 5;

string s, t;
int n;
ll Pow[2*N], HashS[2*N], HashT[N];

ll getHashS(int i, int j){
    return ( HashS[j] - HashS[i-1] * Pow[j - i + 1] + MOD * MOD ) % MOD;
}

ll getHashT(int i, int j){
    return ( HashT[j] - HashT[i-1] * Pow[j - i + 1] + MOD * MOD ) % MOD;
}

void build(){
    n = s.size();
    s = s + s;
    s = ' ' + s;
    t = ' ' + t;

    Pow[0] = 1;
    for (int i = 1; i <= n; i ++)
        Pow[i] = ( Pow[i-1] * base ) % MOD;

    for (int i = 1; i <= 2*n; i ++)
        HashS[i] = ( HashS[i-1] * base + s[i] - 'A' + 1 ) % MOD;

    for (int i = 1; i <= n; i ++)
        HashT[i] = ( HashT[i-1] * base + t[i] - 'A' + 1 ) % MOD;

}

void solve(){
    ll ans = 0;

    for (int i = 1; i <= n; i ++){
        int res = i - 1, d = i, c = i + n - 1;

        while ( d <= c ){
            int mid = ( d + c ) / 2;

            if ( getHashS(i, mid) == HashT[mid - i + 1] ){
                res = mid;
                d = mid + 1;
            }
            else c = mid - 1;
        }

        if ( res == i + n - 1 ) ans += n;
        else if ( getHashS(res + 2, i + n - 1) == getHashT(res - i + 3, n) ) ans ++;
    }

    cout << ans;
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> s >> t;

    build();
    solve();

    return 0;
}
