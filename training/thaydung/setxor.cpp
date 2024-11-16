#include<bits/stdc++.h>
#define BIT(x, k) ((x>>k)&1)
using namespace std;
const int N = 2e5 + 5;

int q, sz = 0;
int trie[N*30][2], cnt[N*30];

void Insert(int x){
    int cur = 0;
    for (int i = 29; i >= 0; i --){
        if ( trie[cur][BIT(x, i)] == -1 )
            trie[cur][BIT(x, i)] = ++sz;
        cur = trie[cur][BIT(x, i)];
        cnt[cur] ++;
    }
}

void Remove(int x){
    int cur = 0;
    for (int i = 29; i >= 0; i --){
        int pre = cur;
        cur = trie[cur][BIT(x, i)];
        cnt[cur] --;
        if ( cnt[cur] == 0 ) trie[pre][BIT(x, i)] = -1;
    }
}

int Get(int x){
    int res = 0, cur = 0;
    for (int i = 29; i >= 0; i --){
        if ( trie[cur][!BIT(x, i)] != -1 ){
            res += 1<<i;
            cur = trie[cur][!BIT(x, i)];
        }
        else cur = trie[cur][BIT(x, i)];
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> q;

    memset(trie, -1, sizeof trie);

    char type;
    int x;
    Insert(0);
    while ( q -- ){
        cin >> type >> x;
        if ( type == '+' ) Insert(x);
        if ( type == '-' ) Remove(x);
        if ( type == '?' ) cout << Get(x) << '\n';
    }

    return 0;
}
