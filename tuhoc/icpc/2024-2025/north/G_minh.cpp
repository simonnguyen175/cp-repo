#include<bits/stdc++.h>

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)

using namespace std;

const int MAXN = 5e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;

string S;
int N;
int f[MAXN], g[MAXN];
int nxt[MAXN];
int res = 0;

int getf(int l, int r) {
    return f[r] - f[l - 1];
}

int getg(int l, int r) {
    return g[r] - g[l - 1];
}

int findpos(int l, int len) {
    int L = l, R = N, ans = -1;
    while (L <= R) {
        int mid = (L + R) / 2;
        if (getg(l, mid) >= len) {
            ans = mid;
            R = mid - 1;
        }
        else L = mid + 1;
    }

    if (ans == -1) return ans;
    return nxt[ans] - 1;
}

void solve(int len) {
    int remove = 0;
    int l = 1;
    while(l <= N) {
        int r = findpos(l, len);
        if (r == -1) {
            remove += getf(l, N);
            break;
        }
        remove += getf(l, r);
        l = r + 2;
    }
    if (S[l - 1] == '1') remove++;
    int remain = f[N] - remove;
    if (remain > 0) res = max(res, (remain + 1) * len + remain);
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    if ( fopen("tmp.inp", "r") ){
        freopen("tmp.inp", "r", stdin);
        freopen("tmp0.out", "w", stdout);
    }


    // srand(time(0));
    // cout << 100000 << '\n';
    // FOR(i, 1, 100000) cout << 0;
    cin >> N >> S;
    S = " " + S;
    S += "0"; S += "0";
    FOR(i, 1, N) f[i] = f[i - 1] + (S[i] == '1');
    FOR(i, 1, N) g[i] = g[i - 1] + (S[i] == '0');
    int ptr = N + 1;
    FORD(i, N, 1) {
        nxt[i] = ptr;
        if (S[i] == '1') ptr = i;
        cout << nxt[i] << ' ';
    }
    cout << '\n';

    FOR(i, 1, N) solve(i);
    res = max(res, N - g[N]);
    cout << res;
}
