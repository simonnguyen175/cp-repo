#include<bits/stdc++.h>
#define ll long long
#define BIT(x, k) ((x>>k)&1)
using namespace std;
const int N = 1e6;

int q, tt = 0, g = 0;
int trie[N][2], sum[N][20][2], cnt[N];

void Insert(int x){
    int cur = 0;
    for (int i = 17; i >= 0; i --){
        if ( trie[cur][BIT(x, i)] == -1 )
            trie[cur][BIT(x, i)] = ++ tt;

        cur = trie[cur][BIT(x, i)];


        cnt[cur] ++;

        for (int j = i; j >= 0; j --)
            sum[cur][j][BIT(x, j)] ++;
    }
}

bool Exist(int x){
    int cur = 0;
    for (int i = 17; i >= 0; i --){
        if ( trie[cur][BIT(x, i)] == -1 )
            return false;
        cur = trie[cur][BIT(x, i)];
    }
    return true;
}

void Erase(int x){
    if ( !Exist(x) ) return;
    int cur = 0;
    for (int i = 17; i >= 0; i --){
        int pre = cur;
        cur = trie[cur][BIT(x, i)];
        cnt[cur] --;

        if ( !cnt[cur] )
            trie[pre][BIT(x, i)] = -1;

        for (int j = i; j >= 0; j --)
            sum[cur][j][BIT(x, j)] --;
    }
}

ll Get(int cur, int k, int id){
    ll res = min(sum[cur][id][BIT(g, id)^1], k) * (1LL << id);

    if ( !id ) return res;

    for (int i = 0; i <= 1; i ++){
        int ncur = trie[cur][i^(BIT(g, id-1))];

        if ( ncur == -1 ) continue;

        if ( k >= cnt[ncur] ){
            for (int j = id - 1; j >= 0; j --)
                res += sum[ncur][j][BIT(g, j)^1] * (1LL << j);
            k -= cnt[ncur];
        }
        else if ( k && k < cnt[ncur] ){
            res += Get(ncur, k, id - 1);
            break;
        }
    }

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    memset(trie, -1, sizeof trie);

    cin >> q;
    while ( q -- ){
        int type, x;
        cin >> type >> x;

        if ( type == 0 ) Insert(x^g);

        if ( type == 1 ) Erase(x^g);

        if ( type == 2 ) g ^= x;

        if ( type == 3 ) cout << Get(0, x, 18) << '\n';
    }

    return 0;
}
