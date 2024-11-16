#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;

int n, m, tt = 0;
int Next[N*21][2], Cnt[N*21][2], H[N*21][2], d[N];

bool fullSubtree(int cnt, int h){
    return ( cnt == (1<<(h-1)) );
}

void Insert(int x){
    bitset<21> bit(x);

    int id = 0;

    for (int i = bit.size()-1; i >= 0; i --){
        if ( Next[id][bit[i]] == -1 ){
            Next[id][bit[i]] = ++ tt;
            H[id][bit[i]] = i + 1;
        }

        Cnt[id][bit[i]] ++;
        id = Next[id][bit[i]];
    }
}

int GetMex(int x){
    bitset<21> bit(x), res;

    int id = 0;

    for (int i = bit.size()-1; i >= 0; i --){
        int opt1 = 0, opt2 = 1;
        if ( bit[i] ) swap(opt1, opt2);

        if ( Next[id][opt1] == -1) break;

        if ( !fullSubtree(Cnt[id][opt1], H[id][opt1]) ){
            id = Next[id][opt1];
        }
        else{
            if ( Next[id][opt2] == -1 ){
                res[i] = 1;
                break;
            }
            res[i] = 1;
            id = Next[id][opt2];
        }
    }

    return res.to_ullong();
}

int main(){
    if ( fopen("mexxor.inp", "r") ){
        freopen("mexxor.inp", "r", stdin);
        freopen("mexxor.out", "w", stdout);
    }

    cin >> n >> m;

    memset(Next, -1, sizeof Next);

    for (int i = 1; i <= n; i ++){
        int x;
        cin >> x;
        if ( d[x] ) continue;
        d[x] = 1;
        Insert(x);
    }

    int pre = 0;
    for (int i = 1; i <= m; i ++){
        int x;

        cin >> x;
        x^=pre;

        cout << GetMex(x) << '\n';

        pre = x;
    }

    return 0;
}
