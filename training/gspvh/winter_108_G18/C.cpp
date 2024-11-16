#include<bits/stdc++.h>
using namespace std;
const int N = 3e6 + 7e3 + 5;

string s, t;
int p[N], del[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("eksplozija.inp", "r", stdin);
    freopen("eksplozija.out", "w", stdout);

    cin >> s >> t;
    int n = s.size() + t.size() + 1;
    s = ' ' + t + '#' + s;

    int k = 0;
    p[1] = 0;
    stack<int> stk;
    stk.push(s[1]);

    for (int i = 2; i <= n; i ++){
        stk.push(i);
        while ( k && s[k+1] != s[i]) k = p[k];
        if ( s[k+1] == s[i] ) k ++;
        p[i] = k;

        if ( p[i] == t.size() ){
            for (int j = 1; j <= t.size(); j ++)
                del[stk.top()] = 1, stk.pop();

            k = p[stk.top()];
        }
    }

    string ans = "";
    for (int i = t.size() + 2; i <= n; i ++)
        if ( !del[i] ) ans += s[i];

    if ( ans == "" ) cout << "miss you baby";
    else cout << ans;

    return 0;
}
