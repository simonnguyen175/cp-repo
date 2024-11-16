#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int base = 3;
const ll MOD = 1e9 + 7;
const int N = 1e3 + 5;

int n[2], len, ok;
string s[2];
ll t[N], Hash[2][N], pw[N];

void make(int tt){
    n[tt] = s[tt].size();
    s[tt] = ' ' + s[tt];
    for (int i = 1; i <= n[tt]; i ++)
        Hash[tt][i] = ( Hash[tt][i-1] * base + s[tt][i] - '0' ) % MOD;
}

ll get(int tt, int l, int r){
    return ( Hash[tt][r] - Hash[tt][l-1] * pw[r-l+1] + MOD*MOD ) % MOD;
}

void xuli(){
    if ( ok ) return;

    int cnt = 0;
    ll hashT = 0;

    for (int i = 1; i <= len; i ++)
        hashT = ( hashT * base + t[i] ) % MOD;

//    for (int i = 1; i <= len; i ++) cout << t[i]; cout << '\n';
//    cout << hashT << '\n';

    for (int tt = 0; tt <= 1; tt ++)
    for (int i = len; i <= n[tt]; i ++)
        if ( get(tt, i-len+1, i) == hashT ) {cnt ++; break;}

    if ( !cnt ){
        ok = 1;
        for (int i = 1; i <= len; i ++)
            cout << t[i];
    }
}

void gen(int id){
    if ( ok ) return;
    for (int i = 0; i <= 1; i ++){
        t[id] = i;
        if ( id == len ) xuli();
        else gen(id+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> s[0] >> s[1];

    pw[0] = 1;
    for (int i = 1; i <= 1000; i ++)
        pw[i] = pw[i-1] * base % MOD;
    make(0);
    make(1);

    for (len = 1; len <= 12; len ++) if ( !ok ){
//        cout << len << " : \n";
        gen(1);
    }

    return 0;
}
