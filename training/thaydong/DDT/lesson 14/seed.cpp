#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5;

int n, tt = 0;
string s;
char st[55];
ll trie[N][2], h[N], Next[N][2];
ll f[55][N];

void Insert(string t){
    int id = 0;

    for (int i = 0; i < t.size(); i ++){
        int c = t[i] - '0';
        if ( trie[id][c] == -1 ){
            trie[id][c] = ++tt;
            h[tt] = i + 1;
        }
        id = trie[id][c];
    }
}

void gen(int id){
    if ( s[id] == '*' )
        for (char x = '0'; x <= '1'; x ++){
            st[id] = (char) x;
            if ( id == s.size() - 1 ){
                string t = "";
                for (int i = 0; i < s.size(); i ++) t += st[i];
                Insert(t);
            }
            else gen(id+1);
        }
    else{
        st[id] = '1';
        if ( id == s.size() -1 ){
            string t = "";
            for (int i = 0; i < s.size(); i ++) t += st[i];
            Insert(t);
        }
        else gen(id+1);
    }
}

int getNode(string t){
    int id = 0;

    for (int i = 0; i < t.size(); i ++){
        int c = t[i] - '0';
        if ( trie[id][c] == -1 ) return -1;
        id = trie[id][c];
    }

    return id;
}

void makeNext(int node, string t){
    for (char c = '0'; c <= '1'; c ++){
        string st = t + (char) c;
        int v = getNode(st);
        while ( v == -1 ){
            st.erase(0, 1);
            v = getNode(st);
        }
        Next[node][c-'0'] = v;
    }
}

void dfs(int node, string t){
    makeNext(node, t);
    for (char c = '0'; c <= '1'; c ++)
        if ( trie[node][c-'0'] != -1 )
            dfs(trie[node][c-'0'], t + (char)c);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("seed.inp", "r") ){
        freopen("seed.inp", "r", stdin);
        freopen("seed.out", "w", stdout);
    }

    cin >> n >> s;
    memset(trie, -1, sizeof trie);
    gen(0);
    dfs(0, "");

    for (int i = 1; i <= tt; i ++)
        if ( h[i] == s.size() ) Next[i][0] = Next[i][1] = i;

    f[0][0] = 1;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j <= tt; j ++){
                (f[i+1][Next[j][0]] += f[i][j]);
                (f[i+1][Next[j][1]] += f[i][j]);
            }

    ll ans = 0;

    for (int i = 1; i <= tt; i ++)
        if ( h[i] == s.size() )
            ( ans += f[n][i] );

    cout << ans;

    return 0;
}
