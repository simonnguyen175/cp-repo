#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

string s, t;
int lens, lent;
int Next[N], dp[N], cnt[N];

void makeKMP(){
    int k = 0;
    Next[1] = 0;
    for (int i = 2; i <= lent; i ++){
        while ( k > 0 && t[k+1] != t[i] ) k = Next[k];
        if ( t[k+1] == t[i] ) k ++;
        Next[i] = k;
    }
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
    cin >> s >> t;
    lens = s.size();
    lent = t.size();
    s = ' ' + s;
    t = ' ' + t;
    makeKMP();
    memset(cnt, 0, sizeof cnt);
    memset(dp, 0, sizeof dp);
    for (int i = lent; i <= lens; i ++){
        bool flag = 1;
        for (int j = 1; j <= lent; j ++)
            if ( s[i-j+1] != '?' && s[i-j+1] != t[lent-j+1]){
                flag = 0;
                break;
            }
        //cout << i << ' ' << flag << '\n';
        dp[i] = dp[i-1];
        if ( flag ){
            cnt[i] = dp[i-lent];
            //cout << cnt[i] << '\n';
            for (int j = Next[lent]; j > 0; j = Next[j])
                cnt[i] = max(cnt[i], cnt[i-lent+j]);
            cnt[i] ++;
            dp[i] = max(dp[i], cnt[i]);
        }
    }

    cout << dp[lens];
    return 0;
}
