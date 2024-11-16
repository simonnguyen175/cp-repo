#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, tt;
int trie[10*N][27], cnt[10*N], sl[10*N];

void Insert(string s){
    int cur = 0, ck = 0;
    for (int i = 0; i < s.size(); i ++){
        if ( trie[cur][s[i]] == -1 )
            trie[cur][s[i]] = ++ tt;
        cur = trie[cur][s[i]];
        cnt[cur] ++;
        if ( !ck ) cout << s[i];
        if ( cnt[cur] == 1 ) ck = 1;
    }
    sl[cur] ++;
    if ( !ck ) cout << ' ' << sl[cur];
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    memset(trie, -1, sizeof trie);
    for (int i = 1; i <= n; i ++){
        string s; cin >> s;
        Insert(s);
    }
    return 0;
}
