#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;

string s, t;
int p[N];

int main(){
    cin >> s >> t;
    s = t + '#' + s + s;
    cout << s << '\n';
    int n = s.size(), m = t.size(); s = ' ' + s;

    p[1] = 0;
    int k = 0, ans = 0;

    for (int i = 2; i <= n; i ++){
        while ( k > 0 && s[k+1] != s[i] ) k = p[k];
        if ( s[k+1] == s[i] ) k ++;
        p[i] = k;
        if ( p[i] == m ) ans += m;
        else if ( p[i] < m && p[i - m - 1] == i - m - 1 ) ans ++;
    }

    for (int i = 2*m + 1; i <= n; i ++){
        cout << i << ' ' << p[i] << '\n';
        if ( p[i] == m ) ans += m;
            else if ( p[i] < m && p[i - m - 1] == m - p[i] - 1 ) ans ++;
    }
    cout << ans;

    return 0;
}
