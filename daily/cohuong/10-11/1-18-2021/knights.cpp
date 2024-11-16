#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 9;
const int dx[] = {-2, 2, 2, -2, -1, 1, 1, -1};
const int dy[] = {1, 1, -1, -1, 2, 2, -2, -2};

int m, n;
int a[10][5], D[100];
int cnt = 0;

struct matrix {
    int v[100][100];
} org, A;

int add(int a, int b) {
    a += b;
    if ( a >= MOD ) a -= MOD;
    return a;
}

int mul(int a, int b) {
    return 1ll * a * b % MOD;
}

matrix mul(matrix a, matrix b) {
    matrix c;
    for (int i = 1; i <= cnt; i ++)
    for (int j = 1; j <= cnt; j ++) c.v[i][j] = 0;
    for (int i = 1; i <= cnt; i ++)
        for (int j = 1; j <= cnt; j ++)
            for (int k = 1; k <= cnt; k ++)
                c.v[i][j] = add(c.v[i][j], mul(a.v[i][k], b.v[k][j]));
    return c;
}

matrix Pow(matrix A, int n)  {
    if ( n == 0 ) return org;
    matrix ans = Pow(A, n / 2);
    ans = mul(ans, ans);
    if ( n % 2 ) ans = mul(ans, A);
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);

    if ( fopen("knights.inp", "r") ){
        freopen("knights.inp", "r", stdin);
        freopen("knights.out", "w", stdout);
    }

    cin >> m >> n;

    if (n == 1) {
    	cout << (1 << m);
    	return 0;
	}

    for (int mask = 0; mask < (1 << (2 * m)); mask ++){
        for (int i = 1, s = 0; i <= m; i ++)
            for (int j = 1; j <= 2; ++j, s ++)
                a[i][j] = mask >> s & 1;

        bool ok = true;
        for (int i = 1; i <= m; i ++) {
            for (int j = 1; j <= 2; j ++) {
                if (a[i][j]) for (int k = 0; k < 4; k ++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x <= 0 || x > m || y <= 0 || y > 2) continue;
                    ok &= !a[x][y];
                }
            }
        }
        cnt += ok;
        if (ok) D[cnt] = mask;
    }

    for (int i = 1; i <= cnt; i ++) org.v[i][i] = 1;

    for (int id1 = 1; id1 <= cnt; id1 ++)
        for (int id2 = 1; id2 <= cnt; id2 ++){
            bool ok = true;
            for (int s = 0; s < 2 * m; s += 2)
                ok &= ((D[id1] >> s & 1) == (D[id2] >> (s + 1) & 1));

            if ( !ok ) continue;

            for (int i = 1, s = 0; i <= m; i ++){
                    for (int j = 1; j <= 2; j ++, s ++)
                a[i][j] = D[id2] >> s & 1;
            }

            for (int i = 1, s = 1; i <= m; i ++, s += 2)
                a[i][3] = D[id1] >> s & 1;

            for (int i = 1; i <= m; i ++){
                for (int j = 1; j <= 3; j ++){
                    if ( a[i][j] ) for (int k = 0; k < 8; k ++){
                        int x = i + dx[k], y = j + dy[k];
                        if (x <= 0 || x > m || y <= 0 || y > 3) continue;
                        ok &= !a[x][y];
                    }
                }
            }

            A.v[id1][id2] = ok;
        }

    A = Pow(A, n - 2);

    int ans = 0;
    for (int i = 1; i <= cnt; i ++) {
        for (int j = 1; j <= cnt; j ++)
            ans = add(ans, A.v[i][j]);
    }

    cout << ans;

    return 0;
}
