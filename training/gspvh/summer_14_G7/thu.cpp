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
#define next   ___next
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

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE.  **/

#define MAX   111
int numNode;
vector<pair<int, int>> adj[MAX];
map<int, map<int, int>> nodes;

void loadTree(void) {
    scanf("%d", &numNode);
    REP(love, numNode - 1) {
        int u, v, c; scanf("%d%d%d", &u, &v, &c);
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    if (numNode == 1) {
        cout << "1\n1" << endl;
        exit(EXIT_SUCCESS);
    }
    if (numNode == 2) {
        cout << "2\n1 2" << endl;
        exit(EXIT_SUCCESS);
    }
}

void dfs(int u, int par, int dist, int root) {
    cerr << dist << ' ' << root << ' ' << u << '\n';
    nodes[dist][root] = u;
    FORE(it, adj[u]) if (it->fi != par) dfs(it->fi, u, dist + it->se, root);
}

void process(void) {
    vector<int> best;
    FOR(i, 1, 2) best.push_back(i);

    FOR(root, 1, numNode) {
        nodes.clear();
        FORE(it, adj[root]) dfs(it->fi, root, it->se, it->fi);
        FORE(it, nodes) if (it->se.size() > best.size()) {
            best.clear();
            map<int, int> &cur = it->se;
            FORE(jt, cur) best.push_back(jt->se);
        }
    }

    cout << best.size() << endl;
    FORE(it, best) cout << *it << " "; cout << endl;
}

int main(void) {
#ifdef ONLINE_JUDGE
    freopen("egalitarianism3.inp", "r", stdin);
    freopen("egalitarianism3.out", "w", stdout);
#endif // ONLINE_JUDGE

    loadTree();
    process();
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/
