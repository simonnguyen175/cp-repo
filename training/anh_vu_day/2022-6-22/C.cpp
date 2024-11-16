#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m, res;
string s, t;
map<string, int> ans;
bitset<N> bit[30], msk;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    cin >> s;

    for (int i = 0; i < n; i ++)
        bit[s[i]-'a'+1][i] = 1;

    while ( m -- ){
        cin >> t;

        if ( ans.find(t) != ans.end() ){
            cout << ans[t] << '\n';
            continue;
        }

        msk = bit[t[0]-'a'+1];
        for (int i = 1; i < t.size(); i ++)
            msk = msk & ( bit[t[i]-'a'+1] >> i );

        res = 0;
        for (int i = msk._Find_first(); i < n; i = msk._Find_next(i))
            res ++, i += t.size() - 1;
        ans[t] = res;
        cout << res << '\n';
    }

    return 0;
}
