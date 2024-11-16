#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll base = 31;

int la, lb, q;
string a, b;
ll Pow[N], HashA[N], HashB[N];

ll getHash(ll Hash[], int i, int j){
    return ( Hash[j] - Hash[i-1] * Pow[j - i + 1] + MOD * MOD ) % MOD;
}

void build(){
    a = ' ' + a;
    b = ' ' + b;

    Pow[0] = 1;
    for (int i = 1; i <= max(la, lb); i ++)
        Pow[i] = ( Pow[i-1] * base ) % MOD;

    for (int i = 1; i <= la; i ++)
        HashA[i] = ( HashA[i - 1] * base + a[i] - 'a' + 1 ) % MOD;

    for (int i = 1; i <= lb; i ++)
        HashB[i] = ( HashB[i - 1] * base + b[i] - 'a' + 1 ) % MOD;

}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> la >> lb >> a >> b >> q;

    build();

    while ( q -- ){
        int l, r, u, v;
        cin >> l >> r >> u >> v;

        int d = 1, len = min(r - l + 1, v - u + 1), c = len, res;

        while ( d <= c ){
            int mid = ( d + c ) / 2;
            if ( getHash(HashA, l, l + mid - 1) == getHash(HashB, u, u + mid - 1) ){
                res = mid;
                d = mid + 1;
            }
            else c = mid - 1;
        }

        //cout << res << ' ' << len << ' ';
        if ( res == len ){
            if ( r - l == v - u ) cout << '=' ;
            else
                if ( r - l < v - u ) cout << '<';
                else cout << '>';
        }
        else{
            //cout << a[l + res] << ' ' << b[u + res] << ' ';
            cout << ( a[l + res] < b[u + res] ? '<' : '>' );
        }
        //cout << '\n';
    }

    return 0;
}
