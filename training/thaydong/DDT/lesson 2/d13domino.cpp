#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int dom[2][56], id[10][10];
unordered_map<ll, ll> f;

ll tinh(int n, ll t){
    if ( n == 0 ) return 1;
    if ( f.count(t) ) return f[t];
    ll res = 0;
    int x = id[dom[0][n]][dom[1][n]];

    if ( (t & (1LL<<x)) == 0 )
        res += tinh(n-1, t|(1LL<<x));

    if ( n >= 2 ){
        int x = id[dom[0][n]][dom[0][n-1]];
        int y = id[dom[1][n]][dom[1][n-1]];
        if ( x != y && ((t&(1LL<<x))==0) && ((t&(1LL<<y))==0) ){
            res += tinh(n-2, t|(1LL<<x)|(1LL<<y));
        }
    }

    f[t] = res;

    return res;
}

int main(){
    cin >> n;

    for (int i = 0; i <= 1; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> dom[i][j];

    int cnt = 0;
    for (int i = 0; i <= 9; i ++)
        for (int j = i; j <= 9; j ++)
            id[i][j] = id[j][i] = cnt ++;

    cout << tinh(n, 0);
    return 0;
}
