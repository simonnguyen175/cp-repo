#include<bits/stdc++.h>
using namespace std;

string s;
int n, p[100005], num[100005];
vector<pair<int, int>> ans;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> s;
    int n = s.size();
    s = ' ' + s;

    int k = 0;
    p[1] = 0;
    for (int i = 2; i <= n; i ++){
        while ( k && s[k+1] != s[i] ) k = p[k];
        if ( s[k+1] == s[i] ) k ++;
        p[i] = k;
    }

    for (int i = 1; i <= n; i ++) num[i] = 1;
    for (int i = n; i >= 1; i --) num[p[i]] += num[i];
    ans.push_back({n, 1});
    for (int i = p[n]; i > 0; i = p[i])
        ans.push_back({i, num[i]});
    cout << ans.size() << '\n';
    for (int i = ans.size()-1; i >= 0; i --)
        cout << ans[i].first << ' ' << ans[i].second << '\n';

    return 0;
}
