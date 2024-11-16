#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, a[8], b[8], na, nb, mid;
ll l, d[15][15];
bool check = 0;

void xuli(){
    if ( check ) return;
    nb = 0;
    for (int i = 2; i <= a[1] - 1; i ++)
        if ( i != mid ) b[++nb] = i;
    for (int i = 1; i < na; i ++)
        for (int j = a[i]+1; j <= a[i+1]-1; j ++)
            if ( j != mid ) b[++nb] = j;
    for (int i = a[na]+1; i <= n; i ++)
        if ( i != mid ) b[++nb] = i;

    unordered_map<ll, bool> m;

    do{
        ll len = d[1][a[1]];
        for (int i = 2; i <= na; i ++) len += d[a[i]][a[i-1]];
        len += d[a[na]][mid];

        m[len] = 1;

        if ( nb == 0 && len + d[mid][1] == l ){
            check = 1;
            return;
        }
    }while (next_permutation(a + 1, a + 1 + na));

    if ( nb == 0 ) return;

    do{
        ll len = d[mid][b[1]];
        for (int i = 2; i <= nb; i ++) len += d[b[i]][b[i-1]];
        len += d[b[nb]][1];
        if ( m[l-len] ){
            check = 1;
            return;
        }
    }while (next_permutation(b + 1, b + 1 + nb));
}

void gen(int i){
    if ( check ) return;
    for (int j = a[i-1] + 1; j <= n - na + i; j ++){
        if ( j == mid ) continue;
        a[i] = j;
        if ( i == na ) xuli();
        else gen(i + 1);
    }
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n >> l;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> d[i][j];

    if ( (n - 2) / 2 == 0  ){
        for (int i = 2; i <= n; i ++) a[i-1] = i;
        do{
            ll len = d[1][a[1]];
            for (int i = 2; i < n; i ++) len += d[a[i]][a[i-1]];
            len += d[a[n-1]][1];
            if ( len == l ){
                check = 1;
                break;
            }
        }while (next_permutation(a + 1, a + n));
    }
    else
        for (int i = 2; i <= n; i ++){
            if ( check ) break;
            mid = i;
            na = (n - 2)/2;
            a[0] = 1;
            gen(1);
        }

    if ( check ) cout << "possible";
    else cout << "impossible";

    return 0;
}
