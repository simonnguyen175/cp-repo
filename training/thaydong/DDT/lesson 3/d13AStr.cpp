#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 111539786;

ll n;
string s;
struct matrix{
    ll v[6][6];
};
int Next[6][2], f[6];

matrix mul(matrix a, matrix b){
    matrix c;
    for (int i = 0; i <= s.size(); i ++)
        for (int j = 0; j <= s.size(); j ++){
            c.v[i][j] = 0;
            for (int k = 0; k <= s.size(); k ++)
                c.v[i][j] = (c.v[i][j] + (a.v[i][k] * b.v[k][j])%MOD) % MOD;
        }
    return c;
}

matrix mu(matrix a, ll n){
    if ( n == 1 ) return a;
    matrix tmp = mu(a, n/2);
    tmp = mul(tmp, tmp);
    if ( n % 2 ) return mul(tmp, a);
    else return tmp;
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    while ( cin >> n >> s ){
         memset(Next, 0, sizeof Next);

         matrix A;
         for (int i = 0; i <= s.size(); i ++)
            for (int j = 0; j <= s.size(); j ++)
                A.v[i][j] = 0;

         for (int i = 0; i <= s.size() - 1; i ++)
            for (int c = 0; c <= 1; c ++){
                string p = s.substr(0, i) + (char) (c +'0');
                while ( p != "" && s.substr(0, p.size()) != p )
                    p.erase(0, 1);
                Next[i][c] = p.size();
            }

        for (int c = 0; c <= 1; c ++)
            Next[s.size()][c] = s.size();

        for (int i = 0; i <= s.size(); i ++)
            for (int j = 0; j <= s.size(); j ++)
                for (int c = 0; c <= 1; c ++)
                    if ( Next[j][c] == i )
                        A.v[i][j] = ( A.v[i][j] + 1 ) % MOD;
        A = mu(A, n);

        ll ans = 0;
        memset(f, 0, sizeof f);
        f[0] = 1;
        for (int i = 0; i < s.size(); i ++)
            for (int j = 0; j <= s.size(); j ++)
                ans = (ans + (f[j] * A.v[i][j])% MOD) % MOD;

        cout << ans << '\n';
    }

    return 0;
}
