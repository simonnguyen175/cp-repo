#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll L, R;
int l[20], r[20], c[20], Pow[20];
ll f[20][2][2][60000];

int Bit(int x, int k){
    return ( x / Pow[k] ) % 3;
}

ll calc(int id, bool ok, bool ok1, int msk){
    //cerr << id << ' ' << ok << ' ' << ok1 << ' ' << msk << '\n';
    if ( id > 19 ) return 1;
    if ( f[id][ok][ok1][msk] != -1 ) return f[id][ok][ok1][msk];

    ll res = 0;
    //cout << max(ok * 9, c[id]) << '\n';
    for (int i = 0; i <= max(ok * 9, c[id]); i ++){
        //cout << Bit(msk, i) << '\n';
        if ( Bit(msk, i) == 2 ) continue;
        res += calc(id + 1, ok | (i < c[id]), ok1 | (i != 0), msk + ( (!ok1 && i == 0) ? 0 : Pow[i] ));
        //cerr << "-> " << id + 1 << ' ' << ( ok | (i < c[id]) ) << ( ok1 | (i != 0)  ) <<  msk + ( (!ok1 && i == 0) ? 0 : Pow[i] ) << '\n';
    }

    f[id][ok][ok1][msk] = res;

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("ex.inp", "r") ){
        freopen("ex.inp", "r", stdin);
        freopen("ex.out", "w", stdout);
    }

    cin >> L >> R; L --;

    Pow[0] = 1;
    for (int i = 1; i <= 10; i ++)
        Pow[i] = Pow[i-1] * 3;

    for (int i = 19; i >= 1; i --) c[i] = R % 10, R /= 10;
    memset(f, -1, sizeof f);
    ll cntR = calc(1, 0, 0, 0);

    for (int i = 19; i >= 1; i --) c[i] = L % 10, L /= 10;
    memset(f, -1, sizeof f);
    ll cntL = calc(1, 0, 0, 0);


    //cout << cntR << ' ' << cntL << '\n';
    cout << cntR - cntL;

    return 0;
}
