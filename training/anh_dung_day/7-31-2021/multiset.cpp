#include<bits/stdc++.h>
using namespace std;
const int N = 7e6 + 5;

int q, tt = 0;
int Next[N][2], cnt[N][2];

void Insert(int x){
    bitset<30> bit(x);

    int id = 0;
    for (int i = bit.size()-1; i >= 0; i --){
        if ( Next[id][bit[i]] ){
            id = Next[id][bit[i]];
            cnt[id][bit[i]] ++;
        }
        else{
            Next[id][bit[i]] = ++ tt;
            id = Next[id][bit[i]];
            cnt[id][bit[i]] ++;
        }
    }
}

void Erase(int x){
    bitset<30> bit(x);

    int id = 0;
    for (int i = bit.size()-1; i >= 0; i --){
        int preid = id;
        id = Next[id][bit[i]];
        cnt[id][bit[i]] --;
        if ( cnt[id][bit[i]] == 0 ) Next[preid][bit[i]] = 0;
    }
}

int Get(int x){
    bitset<30> bit(x);
    bitset<30> res;

    int id = 0;
    for (int i = bit.size()-1; i >= 0; i --){
        if ( Next[id][1-bit[i]] ){
            res[i] = 1;
            id = Next[id][1-bit[i]];
        }
        else{
            res[i] = 0;
            id = Next[id][bit[i]];
        }
    }

    return res.to_ullong();
}

int main(){
    cin >> q;
    Insert(0);
    while ( q -- ){
        char type; int x;
        cin >> type;

        if ( type == '+' ){
            cin >> x;
            Insert(x);
        }

        if ( type == '-' ){
            cin >> x;
            Erase(x);
        }

        if ( type == '?' ){
            cin >> x;
            cout << Get(x) << '\n';
        }
    }
}
