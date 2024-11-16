#include<bits/stdc++.h>
#define simon "numbers"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;

ll A, B;
int a[20], b[20];
ll f[20][15][15][2][2];

ll calca(int id, int s1, int s2, bool ok1, bool ok2){
    if ( id > 19 ) return 1;

    if ( f[id][s1][s2][ok1][ok2] != -1 ) return f[id][s1][s2][ok1][ok2];

    //cout << id << ' ' << s1 << ' ' << s2 << ' ' << ok1 << ' ' << ok2 << '\n';

    ll res = 0;
    for (int c = 0; c <= max(a[id], ok1 * 9); c ++){
        if ( !ok2 ){
            //cout << "->" << id + 1 << ' ' << c << ' ' << 10 << ' ' << (ok1 |= ( c < a[id] )) << ' ' << (ok2 |= ( c != 0 )) << '\n';
            res = res + calca(id + 1, c, 10, ok1 | ( c < a[id] ), ok2 | ( c != 0 ));
        }
        else{
            //cout << "->" << id + 1 << ' ' << c << ' ' << s1 << ' ' << (ok1 |= ( c < a[id] )) << ' ' << ok2 << '\n';
            if ( c != s2 && c != s1 ) res = res + calca(id + 1, c, s1, ok1 | ( c < a[id] ), ok2 );
        }
    }

    f[id][s1][s2][ok1][ok2] = res;

    return res;
}


ll calcb(int id, int s1, int s2, bool ok1, bool ok2){
    if ( id > 19 ) return 1;

    if ( f[id][s1][s2][ok1][ok2] != -1 ) return f[id][s1][s2][ok1][ok2];

    //cout << id << ' ' << s1 << ' ' << s2 << ' ' << ok1 << ' ' << ok2 << '\n';

    ll res = 0;
    for (int c = 0; c <= max(b[id], ok1 * 9); c ++){
        if ( !ok2 ){
            //cout << "->" << id + 1 << ' ' << c << ' ' << 10 << ' ' << (ok1 |= ( c < a[id] )) << ' ' << (ok2 |= ( c != 0 )) << '\n';
            res = res + calcb(id + 1, c, 10, ok1 | ( c < b[id] ), ok2 | ( c != 0 ));
        }
        else{
            //cout << "->" << id + 1 << ' ' << c << ' ' << s1 << ' ' << (ok1 |= ( c < a[id] )) << ' ' << ok2 << '\n';
            if ( c != s2 && c != s1 ) res = res + calcb(id + 1, c, s1, ok1 | ( c < b[id] ), ok2 );
        }
    }

    f[id][s1][s2][ok1][ok2] = res;

    return res;
}

int main(){
    FASTio
    if ( fopen(simon".in", "r") ){
        freopen(simon".in", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> A >> B; ll tmp = A; A --;
    for (int i = 19; i >= 1; i --){ a[i] = A % 10; A /= 10; }
    for (int i = 19; i >= 1; i --){ b[i] = B % 10; B /= 10; }

    if ( !tmp ){
        memset(f, -1, sizeof f);
        cout << calcb(1, 10, 10, 0, 0);
        return 0;
    }

    memset(f, -1, sizeof f);
    ll cntb = calcb(1, 10, 10, 0, 0);

    memset(f, -1, sizeof f);
    ll cnta = calca(1, 10, 10, 0, 0);

    cout << cntb - cnta;

    return 0;
}
