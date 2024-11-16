#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

string s;
int n, z[N], t[N];
bool xx[N];

void makeZ(){
    n = s.size();
    s = ' ' + s;
    z[1] = n;
    for (int i = 2, l = 1, r = 1; i <= n; i ++){
        if ( i <= r )
            z[i] = min(z[i-l+1], r - i + 1);
        while ( i + z[i] <= n && s[z[i]+1] == s[i+z[i]] )
            z[i] ++;

        if ( z[i] == 0 ) continue;

        if ( i + z[i] - 1 > r )
            l = i, r = i + z[i] - 1;
    }
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> s;
    makeZ();
    int cnt = 0;
    for (int i = 1; i <= n; i ++){
        if ( z[n-i+1] == i ) xx[i] = 1, cnt ++;
        if ( z[i] > 0 ) t[1] ++, t[z[i]+1] --;
    }
    for (int i = 1; i <= n; i ++) cout << z[i] << ' ';

    cout << cnt << '\n';
    for (int i = 2; i <= n; i ++) t[i] += t[i-1];
    for (int i = 1; i <= n; i ++) if ( xx[i] ) cout << i << ' ' << t[i] << '\n';
    return 0;
}
