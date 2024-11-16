#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

string s;
int n;
int nxt[N][30], dp[N];

void ckmn(int &a, int b){
    a = min(a, b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> s;
    n = s.size();
    s = ' ' + s;

    for (int j = 0; j <= 25; j ++) nxt[n+1][j] = n+1;
    for (int i = n; i >= 0; i --){
        for (int j = 0; j <= 25; j ++)
            nxt[i][j] = nxt[i+1][j];
        if ( i ) nxt[i][s[i]-'a'] = i;
    }

    for (int i = 0; i <= n; i ++) dp[i] = n+1;
    dp[n+1] = 0;
    for (int i = n; i >= 0; i --)
    for (int j = 0; j <= 25; j ++)
        ckmn(dp[i], dp[nxt[i+1][j]] + 1);


    string ans = "";
    int len = dp[0], pos = 0;
    while ( len ){
        for (int j = 0; j <= 25; j ++)
            if ( dp[nxt[pos+1][j]] == len-1 ){
                pos = nxt[pos+1][j];
                ans += (char) ('a'+j);
                len --;
                break;
            }
    }

    cout << ans;

    return 0;
}
