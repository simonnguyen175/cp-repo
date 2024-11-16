#include<bits/stdc++.h>
using namespace std;

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
}

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

int S(int n){
    if ( n % 2 == 0 ){
        n /= 2;
    }
    else{
        (n + 1) /= 2;
    }

    if ( n % 3 == 0 )
}

void update(int id, int l, int r, int u, int v, int m){
    if ( r < u || l > v ) return;
    if ( u <= l && r <= v ){
        int k = ()
    }
}

int main(){
    cin >> n >> q;
    cin >> q;
    n *= 2;
    while ( q -- ){
        cin >> type;
        if ( type == 1 ){
            cin >> x >> m;
            update(1, 1, n, x, x + m, m);
        }
        else{
            cin >> i >> j;
            if ( j < i ) j += n;
            cout << get(1, 1, n, i, j) << '\n';
        }
    }

    return 0;
}
