#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, q, sz;
string s[N];
int trie[N*26][26], cnt[N*26], leaf[N*26], d[N][26][26], add[N], p[26];

void Insert(string &s){
    int cur = 0;
    for (int i = 0; i < s.size(); i ++){
        if ( trie[cur][s[i]-'a'] == -1 )
            trie[cur][s[i]-'a'] = ++sz;
        cur = trie[cur][s[i]-'a'];
        cnt[cur] ++;
    }
    leaf[cur] = 1;
}

void Make(int id){
    int cur = 0;
    for (int i = 0; i < s[id].size(); i ++){
        int c = s[id][i] - 'a';
        for (int j = 0; j <= 25; j ++)
            if ( trie[cur][j] != -1 && j != c )
                d[id][c][j] += cnt[trie[cur][j]];
        cur = trie[cur][c];
        add[id] += leaf[cur];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("resort.inp", "r", stdin);
    freopen("resort.out", "w", stdout);

    cin >> n;
    memset(trie, -1, sizeof trie);
    for (int i = 1; i <= n; i ++){
        cin >> s[i];
        Insert(s[i]);
    }
    for (int i = 1; i <= n; i ++)
        Make(i);

    cin >> q;
    while ( q -- ){
        int k;
        string ord;
        cin >> k >> ord;

        for (int i = 0; i <= 25; i ++)
            p[ord[i]-'a'] = i;

        int ans = 0;
        for (int i = 0; i <= 25; i ++)
        for (int j = 0; j <= 25; j ++) if ( i != j && p[i] > p[j] )
            ans += d[k][i][j];

        cout << ans + add[k] << '\n';
    }

    return 0;
}
