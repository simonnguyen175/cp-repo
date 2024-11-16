#include<bits/stdc++.h>
#define simon "magic"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int n, k;
string s;
set<char> cont;

namespace sub2{
    ll ans = 0;

    void solve(){
        for (int i = 1; i <= n; i ++){
            int cnt[60]; memset(cnt, 0, sizeof cnt);
            for (int j = i; j >= 1; j --){
                cnt[s[j]-'A'+1] ++;
                int tmp = cnt[s[j]-'A'+1];
                bool flag = 1;

                for (auto v : cont)
                    if ( cnt[v-'A'+1] != tmp ) { flag = 0; break; }

                if ( flag ) ans = ( ans + 1 ) % MOD;
            }
        }
        cout << ans;
    }
}

namespace sub3{
    ll ans = 0, f[2];
    char s0, s1;
    map<int, int> d;

    void solve(){
        d[0] = 1;
        s0 = *cont.begin(); s1 = *cont.rbegin();
        for (int i = 1; i <= n; i ++){
            if ( s[i] == s0 ) f[0] ++;
            else f[1] ++;
            ( ans += d[f[0]-f[1]] ) %= MOD;
            d[f[0]-f[1]] ++;
        }
        cout << ans;
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> s;
    s = ' ' + s;

    for (int i = 1; i <= n; i ++)
        cont.insert(s[i]);

    k = cont.size();

    if ( n <= 2000 )
        sub2::solve();
    else
        sub3::solve();

    return 0;
}
