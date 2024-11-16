
#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE. **/


const int MOD = 998244353;
#define SUM(x, y) ((x) + (y) >= MOD ? (x) + (y) - MOD : (x) + (y))
void add(int &x, const int &y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

class SegmentTree {
private:
    vector<int> tree, lazy, sumCoeff;
    int n;

    void build(const vector<int> &coeff, int i, int l, int r) {
        if (l > r) return;
        if (l == r) {
            sumCoeff[i] = coeff[l];
            return;
        }
        int m = (l + r) >> 1;
        build(coeff, 2 * i, l, m);
        build(coeff, 2 * i + 1, m + 1, r);
        sumCoeff[i] = SUM(sumCoeff[2 * i], sumCoeff[2 * i + 1]);
    }

    void pushDown(int i) {
        FOR(j, 2 * i, 2 * i + 1) {
            add(lazy[j], lazy[i]);
            add(tree[j], 1LL * lazy[i] * sumCoeff[j] % MOD);
        }
        lazy[i] = 0;
    }

    void update(int i, int l, int r, int u, int v, int c) {
        if (l > v || r < u || l > r || v < u) return;
        if (u <= l && r <= v) {
            add(tree[i], 1LL * c * sumCoeff[i] % MOD);
            add(lazy[i], c);
            return;
        }

        pushDown(i);
        int m = (l + r) >> 1;
        update(2 * i, l, m, u, v, c);
        update(2 * i + 1, m + 1, r, u, v, c);
        tree[i] = SUM(tree[2 * i], tree[2 * i + 1]);
    }

    int getSum(int i, int l, int r, int u, int v) {
        if (l > v || r < u || l > r || v < u) return 0;
        if (u <= l && r <= v) return tree[i];

        pushDown(i);
        int m = (l + r) >> 1;
        int L = getSum(2 * i, l, m, u, v);
        int R = getSum(2 * i + 1, m + 1, r, u, v);
        return SUM(L, R);
    }

public:
    SegmentTree(int n = 0, const vector<int> &coeff = vector<int>()) {
        this->n = n;
        if (n > 0) {
            REP(i, 30) if (MASK(i) >= n) {
                tree.assign(MASK(i + 1) + 3, 0);
                lazy.assign(MASK(i + 1) + 3, 0);
                sumCoeff.assign(MASK(i + 1) + 3, 0);
                build(coeff, 1, 1, n);
                return;
            }
            assert(false);
        }
    }

    void update(int l, int r, int c) {
        update(1, 1, n, l, r, c);
    }

    int getSum(int l, int r) {
        return getSum(1, 1, n, l, r);
    }
};

#define MAX   500500
int numNode, numQuery, cnt;
vector<int> children[MAX];
int high[MAX], sta[MAX], fin[MAX];
SegmentTree common, highAdd;

void loadTree(void) {
    int subtask; scanf("%d%d", &subtask, &numNode);
    FOR(i, 2, numNode) {
        int p; scanf("%d", &p);
        children[p].push_back(i);
    }

    for (int i = 1; i <= numNode; i ++){
        cout << i << " : \n";
        for (int v : children[i]) cout << v << ' ';
        cout << '\n';
    }
}

void dfs(int u) {
    sta[u] = ++cnt;
    FORE(it, children[u]) {
        high[*it] = high[u] + 1;
        dfs(*it);
    }
    fin[u] = cnt;
}

void update(int node, int delta, int prog) {
    delta = delta % MOD + MOD;
    if (delta >= MOD) delta -= MOD;
    prog = prog % MOD + MOD;
    if (prog >= MOD) prog -= MOD;

    common.update(sta[node], fin[node], (delta + 1LL * prog * high[node]) % MOD);
    highAdd.update(sta[node], fin[node], prog == 0 ? prog : MOD - prog);
}

int getSum(int l, int r) {
    int a = common.getSum(l, r);
    int b = highAdd.getSum(l, r);
    return SUM(a, b);
}

void process(void) {
    dfs(1);
    vector<int> highPerStart(numNode + 1);
    FOR(i, 1, numNode) highPerStart[sta[i]] = high[i];
    highAdd = SegmentTree(numNode, highPerStart);

    FORE(it, highPerStart) *it = 1;
    common = SegmentTree(numNode, highPerStart);

    char input[6];
    scanf("%d", &numQuery);
    REP(love, numQuery) {
        int node; scanf("%s%d", input, &node);
        if (input[0] == 'a') {
            int delta, prog; scanf("%d%d", &delta, &prog);
            update(node, delta, prog);
        } else printf("%d ", getSum(sta[node], input[0] == 'g' ? sta[node] : fin[node]));
    }
    printf("\n");
}

int main(void) {

#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("talltree.inp", "r", stdin);
    freopen("talltree.out", "w", stdout);
#endif // ONLINE_JUDGE

    loadTree();
    process();
    return 0;
}


/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/
