#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;

int t;
string s;
pi cnt[30];
char sw[10000005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> t;
    while ( t -- ){
        cin >> s;
        vector<int> s1, s2, id[30];

        for (int i = 1; i <= 26; i ++)
            cnt[i].fi = 0, cnt[i].se = i;
        for (int i = 0; i < s.size(); i ++){
            cnt[s[i]-'a'+1].fi ++;
            id[s[i]-'a'+1].pb(i);
        }

        sort(cnt+1, cnt+1+26, greater<pi>());

        if ( cnt[1].first > s.size()/2 ){
            cout << "Impossible" << '\n';
            continue;
        }

        for (int i = 1; i <= 26; i ++)
            for (int p : id[cnt[i].se]){
                s1.pb(p);
                if ( i >= 2 ) s2.pb(cnt[i].se);
            }

        for (int p : id[cnt[1].se]) s2.pb(cnt[1].se);

        for (int i = 0; i < s1.size(); i ++)
            sw[s1[i]] = (char) ('a' + s2[i] - 1);

        for (int i = 0; i < s.size(); i ++) cout << sw[i];

        cout << '\n';
    }
    return 0;
}
