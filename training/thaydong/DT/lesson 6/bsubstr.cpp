#include<bits/stdc++.h>
#define ll long long
using namespace std;

string s, t;
int n, cnt[30], num[30];

bool check(){
    for (int i = 1; i <= 26; i ++)
        if ( num[i] > cnt[i] ) return 0;
    return 1;
}

int main(){
    if ( fopen("bsubstr.inp", "r") ){
        freopen("bsubstr.inp", "r", stdin);
        freopen("bsubstr.out", "w", stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> s >> t;
    for (int i = 0; i < t.size(); i ++)
        cnt[t[i]-'a'+1] ++;

    n = s.size();
    s = ' ' + s;

    int l = 1;
    ll ans = 0;
    for (int i = 1; i <= n; i ++){
        num[s[i]-'a'+1] ++;
        while ( !check() && l <= i ) num[s[l]-'a'+1] --, l ++;
        ans += i - l + 1;
    }

    cout << ans;

    return 0;
}
