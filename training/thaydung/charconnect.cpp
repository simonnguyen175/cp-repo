#include<bits/stdc++.h>
using namespace std;

int n;
int degin[50], degout[50];

void solve(){
    cin >> n;
    for (int i = 0; i <= 26; i ++)
        degin[i] = degout[i] = 0;

    for (int i = 1; i <= n; i ++){
        string s;
        cin >> s;

        degout[s.front()-'a'] ++;
        degin[s.back()-'a'] ++;
    }

    int cnt = 0, cnt1 = 0, ck = 1;
    for (int i = 0; i < 26; i ++){
        if ( degin[i] == degout[i] + 1 ) cnt ++;
        else if ( degin[i] + 1 == degout[i] ) cnt1 ++;
        else if ( degin[i] != degout[i] ) ck = 0;
    }

    if ( cnt <= 1 && cnt1 <= 1 && ck )
        cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
