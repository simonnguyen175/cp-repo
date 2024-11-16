#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 19972207;

int L, la, lb;
string a, b;
int f[N][2][2];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    return a;
}

ll calc(int id, int ok1, int ok2){
    if ( id > L ){
        int c = ok1;
        c &= ( ok2 || ( !ok2 && lb > L ) );
        return c;
    }

    if ( f[id][ok1][ok2] != -1 ) return f[id][ok1][ok2];

    int l, r;
    if ( ok1 ) l = 'a'; else l = max('a', a[id]);
    if ( ok2 ) r = 'z'; else r = b[id];

    ll res = 0;

    for (int c = l; c <= r; c ++)
        res = add(res, calc(id+1, ok1|(c>a[id]), ok2|(c<b[id])) );

    f[id][ok1][ok2] = res;

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("strings.inp", "r") ){
        freopen("strings.inp", "r", stdin);
        freopen("strings.out", "w", stdout);
    }

    cin >> L;
    cin >> a >> b;

    la = a.size(), lb = b.size();

    while ( la < L )
        a += (char)('a'-1), la ++;

    while ( lb < L )
        b += (char)('a'-1), lb ++;

    a = ' ' + a;
    b = ' ' + b;
    memset(f, -1, sizeof f);

    cout << calc(1, 0, 0);

    return 0;
}
