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

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE. **/

struct Binary {
    int first, second, third;

    Binary(int x = 0, int y = 0, int z = 0) {
        if (x < y) swap(x, y);
        if (z > x) {
            int t = z; z = y; y = x; x = t;
        } else if (z > y) swap(y, z);

        if (x == y) {
            first = x + 1;
            second = z;
            third = -1;
        } else if (y == z) {
            if (x == y + 1) {
                first = x + 1;
                second = third = -1;
            } else {
                first = x;
                second = y + 1;
                third = -1;
            }
        } else {
            first = x; second = y; third = z;
        }
    }

    int compare(const Binary &b) const {
        #define COMPARE(x, y) (((x) > (y)) - ((x) < (y)))
        if (first != b.first) return COMPARE(first, b.first);
        else return second != b.second ? COMPARE(second, b.second) : COMPARE(third, b.third);
    }

    #define DEFINE_OPERATOR(x) bool operator x (const Binary &b) const { return compare(b) x 0; }
    DEFINE_OPERATOR(<)  DEFINE_OPERATOR(>)
    DEFINE_OPERATOR(<=) DEFINE_OPERATOR(>=)
    DEFINE_OPERATOR(==) DEFINE_OPERATOR(!=)
    #undef DEFINE_OPERATOR
};

#define MAX   3030
int firstRank[MAX], secondRank[MAX], n;
int initOrder[MAX];

bool CompInitRank(const int &x, const int &y) {
    return Binary(firstRank[x], secondRank[x]) < Binary(firstRank[y], secondRank[y]);
}

void init(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &firstRank[i]);
    FOR(i, 1, n) scanf("%d", &secondRank[i]);
    FOR(i, 1, n) initOrder[i] = i;
    sort(initOrder + 1, initOrder + n + 1, CompInitRank);
//    FOR(i, 1, n) printf("At %d: %d (%d, %d)\n", i, initOrder[i], firstRank[initOrder[i]], secondRank[initOrder[i]]);

}

bool canBeAtLeast(int index, int k) {
    Binary owner(firstRank[index], secondRank[index], 1);
//    printf("Owner ranking: %d %d %d -> %d %d %d\n", firstRank[index], secondRank[index], 1,
//                                                    owner.first, owner.second, owner.third);
    int j = n;
    FOR(i, 1, n - k) {
        if (initOrder[j] == index) j--;
        int tmp = initOrder[j--];
        Binary binary(firstRank[tmp], secondRank[tmp], k + i);
//        printf("Person #%d: %d %d %d -> %d %d %d\n", tmp, firstRank[tmp], secondRank[tmp], k + i,
//                                                     binary.first, binary.second, binary.third);

        if (Binary(firstRank[tmp], secondRank[tmp], k + i) < owner) return false;
    }
    return true;
}

bool canBeAtMost(int index, int k) {
    Binary owner(firstRank[index], secondRank[index], n);
    int j = 1;
    FOR(i, 1, k - 1) {
        if (initOrder[j] == index) j++;
        int tmp = initOrder[j++];
        if (Binary(firstRank[tmp], secondRank[tmp], k - i) >= owner) return false;
    }
    return true;
}

int findBest(int index) {
    int L = 1, R = n;
    while (true) {
        if (L == R) return L;
        if (R - L == 1) return canBeAtLeast(index, L) ? L : R;
        int M = (L + R) >> 1;
        if (canBeAtLeast(index, M)) R = M; else L = M + 1;
    }
}

int findWorst(int index) {
    int L = 1, R = n;
    while (true) {
        if (L == R) return R;
        if (R - L == 1) return canBeAtMost(index, R) ? R : L;
        int M = (L + R) >> 1;
        if (canBeAtMost(index, M)) L = M; else R = M - 1;
    }
}

void process(void) {
    FOR(i, 1, n) printf("%d %d\n", findBest(i), findWorst(i));
}

int main(void) {
#ifdef ONLINE_JUDGE
    freopen("ranking.inp", "r", stdin);
    freopen("ranking.out", "w", stdout);
#endif // ONLINE_JUDGE
    init();
    process();
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/
