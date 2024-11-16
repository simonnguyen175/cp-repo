#include <bits/stdc++.h>
#define TASK "BOMB"

using namespace std;

#define free __free
#define int long long
#define ULL unsigned long long
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef vector < int > BigInt;

const int N = 35;
const int BASE = (int) 1e18;

int m, n, free;
vector < vector < int > > a;
vector < int > b;
int dirx[5] = {0, 0, 1, -1};
int diry[5] = {1, -1, 0, 0};
int infor[N][N];

void print(const BigInt &a) {
    int n = a.size() - 1;
    cout << a[n];
    for(int i = n-1; i >= 0; --i)
        cout << setfill('0') << setw(18) << a[i];
}
BigInt operator + (const BigInt &a, const BigInt &b) {
    BigInt c; ULL carry = 0;
    for(int i = 0; i < a.size() || i < b.size(); ++i) {
        if (i < a.size()) carry += a[i];
        if (i < b.size()) carry += b[i];
        c.push_back(carry % BASE); carry /= BASE;
    }
    if (carry) c.push_back(carry); return c;
}
int id(int i, int j) {
    return (i - 1) * n + j;
}
void Gauss_Elimination(vector < vector < int > > &a, int r, int c) {
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j)
            if (a[i][j]) {
                for(int k = 0; k < r; ++k)
                    if (k != i && a[k][j]) {
                        for(int id = 0; id <= c; ++id)
                            a[k][id] ^= a[i][id];
                    }
                break;
            }
    }
    for(int i = 0; i < r; ++i) {
        bool OK = true;
        for(int j = 0; j < c; ++j)
            if (a[i][j]) {
                OK = false;
                break;
            }
        if (OK) {
            if (a[i][c]) {
                cout << 0;
                return;
            } else free ++;
        }
    }
    BigInt rez = {1};
    for(int i = 1; i <= free; ++i)
        rez = rez + rez;
    print(rez);
}
main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);

    fast;

    cin >> m >> n;
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> infor[i][j];

    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
            b.push_back(0);
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
            if (infor[i][j] != -1) {
                a.push_back(b);
                for(int dir = 0; dir < 4; ++dir) {
                    int x = i + dirx[dir], y = j + diry[dir];
                    if (x > 0 && x <= m && y > 0 && y <= n) {
                        a[a.size()-1][id(x, y)-1] = 1;
                    }
                }
                a[a.size()-1].push_back(infor[i][j]);
            } else free ++;
    Gauss_Elimination(a, a.size(), m*n);

    return 0;
}
