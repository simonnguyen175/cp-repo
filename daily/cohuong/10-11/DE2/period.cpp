#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int t = 0, n;
string s;
int p[N];

void solve(){
    if ( n == 0 ) return;

    cin >> s;
    s = ' ' + s;

    p[1] = 0;
    int k = 0;
    for (int i = 2; i <= n; i ++){
        while ( k && s[k+1] != s[i] ) k = p[k];
        if ( s[k+1] == s[i] ) k ++;
        p[i] = k;
    }

    cout << "Test case #" << ++t << '\n';

    for (int i = 2; i <= n; i ++)
        if ( i % ( i - p[i] ) == 0 && p[i] )
            cout << i << ' ' << i / ( i - p[i] ) << '\n';

    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("period.in", "r") ){
        freopen("period.in", "r", stdin);
        freopen("period.out", "w", stdout);
    }

    while ( cin >> n ) solve();

    return 0;
}
