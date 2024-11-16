#include <bits/stdc++.h>
#define TASK "latxu"

using namespace std;

#define free __free
#define int long long
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N = 34;
const int inf = (int)1e9+7;

int m, n, rez = inf;
string infor[N];
vector < vector < int > > a, c;
vector < int > b;
int dirx[6] = {0, 0, 1, -1, 0};
int diry[6] = {1, -1, 0, 0, 0};

int id(int i, int j) {
    return (i - 1) * n + j;
}
int get(int x, int k) { return (x >> k) & 1;}
namespace Solve {
    bool check(vector < vector < int > > &a) {
        for(int i = 0; i < a.size(); ++i) {
            bool OK = true;
            for(int j = 0; j < a[i].size()-1; ++j)
                if (a[i][j]) {
                    OK = false;
                    break;
                }
            if (OK) {
                if (a[i][a[i].size()-1]) return false;
            }
        }
        return true;
    }
    void Gauss_Elimination(vector < vector < int > > &a, int n) {
        int column = 0;
        int row;
        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                if (a[j][column]) {
                    swap(a[i], a[j]);
                    break;
                }
            }
            if (!a[i][column]) {
                if (column < n-1) column ++; else {
                    row = i;
                    break;
                }
                i --;
                continue;
            }
            for(int j = 0; j < n; ++j)
                if (j != i && a[j][column]) {
                    for(int k = 0; k <= n; ++k)
                        a[j][k] ^= a[i][k];
                }
        }

        if (!check(a)) {
            rez = min(rez, inf);
            return;
        }

        //for(int i = 0; i < n; ++i) {
          //  for(int j = 0; j <= n; ++j) cout << a[i][j];
            //cout << '\n';
        //}
        //cout << '\n';
        int maxBit = n - row;
        for(int i = 0; i < (1 << maxBit); ++i) {
            int ans = __builtin_popcount(i);
            //cout << "check " << i << '\n';
            for(int j = 0; j < row; ++j) {
                int x = a[j][n];
                for(int k = 0; k < maxBit; ++k)
                    if (a[j][k+row]) x ^= get(i, k);
                if (x) ans ++;
                //cout << x << ' ';
            }
            //cout << '\n';
            //cout << ans << '\n';
            rez = min(rez, ans);
        }

    }
    void run() {
        Gauss_Elimination(a, m*n);
    }
}
main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);

    fast;

    string s;
    while (cin >> s) {
        infor[++m] = s;
        infor[m] = ' ' + infor[m];
    }
    n = s.size();

    b.resize(m*n);

    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            int x = (infor[i][j] == 'b' ? 0 : 1);
            c.push_back(b);
            for(int dir = 0; dir < 5; ++dir) {
                int x = i + dirx[dir], y = j + diry[dir];
                if (x > 0 && x <= m && y > 0 && y <= n) {
                    c[c.size()-1][id(x, y)-1] = 1;
                }
            }
            c[c.size()-1].push_back(x);
        }
    }
    a = c;
    Solve :: run();

    for(int i = 0; i < m*n; ++i)
        c[i][c[i].size()-1] ^= 1;
    a = c;
    Solve :: run();
    cout << ((rez == inf) ? -1 : rez);
    //if (rez == inf) cout << "Impossible"; else cout << rez;
}

