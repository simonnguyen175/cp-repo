#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, q, sz = 0;
int trie[N*20][26], cnt[N*20];

void Insert(string s){
    int cur = 0;
    for (int i = 0; i < s.size(); i ++){
        if ( trie[cur][s[i]-'a'] == -1 )
            trie[cur][s[i]-'a'] = ++sz;
        cur = trie[cur][s[i]-'a'];
        cnt[cur] ++;
    }
}

int Get(string s){
    int cur = 0, res = 0;
    for (int i = 0; i < s.size(); i ++){
        if ( trie[cur][s[i]-'a'] == -1 ) return 0;
        cur = trie[cur][s[i]-'a'];
    }
    return cnt[cur];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("words.inp", "r", stdin);
    freopen("words.out", "w", stdout);

    cin >> n;
    memset(trie, -1, sizeof trie);
    for (int i = 1; i <= n; i ++){
        string s;
        cin >> s;
        Insert(s);
    }
    cin >> q;
    for (int i = 1; i <= q; i ++){
        string s;
        cin >> s;
        cout << Get(s) << '\n';
    }

    return 0;
}
