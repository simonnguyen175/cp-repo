#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, cnt[30];
map<ll, int> d;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("pairpalin.inp", "r") ){
        freopen("pairpalin.inp", "r", stdin);
        freopen("pairpalin.out", "w", stdout);
    }

    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i ++){
        string s; cin >> s;
        ll mask = 0;

        memset(cnt, 0, sizeof cnt);

        for (int j = 0; j < s.size(); j ++)
            cnt[s[j]-'a'+1] = ( cnt[s[j]-'a'+1] + 1 ) % 2;

        for (int j = 1; j <= 26; j ++)
            mask |= cnt[j] << (j-1);

        ans += d[mask];

        for (int j = 1; j <= 26; j ++)
            ans += d[mask ^ (1<<(j-1))];

        d[mask] ++;
    }

    cout << ans;

    return 0;
}
