#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;

int n, sz = 0;
char c[N];
int trie[N][30], last[N], d[N][N];
struct node{
    int x, y;
} trace[N][N];

void Insert(string s){
    int cur = 0;
    for (int i = 0; i < s.size(); i ++){
        if ( trie[cur][s[i]-'a'] == -1 ){
            trie[cur][s[i]-'a'] = ++sz;
            c[sz] = s[i];
        }
        cur = trie[cur][s[i]-'a'];
    }
    last[cur] = 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n;
    memset(trie, -1, sizeof trie);
    for (int i = 1; i <= n; i ++){
        string s;
        cin >> s;
        Insert(s);
    }

    memset(d, -1, sizeof d);
    queue<node> q;
    d[0][0] = 0;
    q.push({0, 0});

    while ( q.size() ){
        int x = q.front().x, y = q.front().y;
        q.pop();

        if ( x != y && last[x] && last[y] ){
            string X = "", Y = "";
            while ( x || y ){
                if ( x && y ) X += c[x], Y += c[y];
                else{
                    if ( !x ) X += '+';
                    if ( !y ) Y += '+';
                }
                node tmp = trace[x][y];
                x = tmp.x, y = tmp.y;
            }
            reverse(X.begin(), X.end());
            reverse(Y.begin(), Y.end());
            cout << X << '\n' << Y << '\n';
            return 0;
        }

        for (int i = 0; i <= 25; i ++) if ( trie[x][i] != -1 && trie[y][i] != -1 ){
            int nx = trie[x][i], ny = trie[y][i];

            if ( d[nx][ny] != -1 ) continue;

            d[nx][ny] = d[x][y] + 1;
            trace[nx][ny] = {x, y};
            q.push({nx, ny});

            if ( last[nx] && d[0][ny] == -1 ){
                d[0][ny] = d[nx][ny];
                trace[0][ny] = {nx, ny};
                q.push({0, ny});
            }

            if ( last[ny] && d[nx][0] == -1 ){
                d[nx][0] = d[nx][ny];
                trace[nx][0] = {nx, ny};
                q.push({nx, 0});
            }
        }
    }

    cout << -1;

    return 0;
}
