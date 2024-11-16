#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

const int N = 500005;
const int INF = 0x3f3f3f3f;

struct query {
    int l, r, id;
};

int K;
int a[N], lef[N], rig[N], ans[N];
query que[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    K = sqrt(n);
    vector<int> val;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        val.push_back(a[i]);
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    for (int i = 0; i < n; i++)
        a[i] = lower_bound(val.begin(), val.end(), a[i]) - val.begin();
    for (int i = 0; i < m; i++) {
        cin >> que[i].l >> que[i].r; que[i].id = i;
        que[i].l--; que[i].r--;
    }
    sort(que, que + m, [&](query x, query y) {
        return x.l / K != y.l / K ? x.l < y.l : x.r < y.r;
    });
    memset(lef, 0xc0, sizeof lef);
    for (int i = 0; i < m; i++)
        if (que[i].r - que[i].l + 1 <= K) {
            ans[que[i].id] = INF;
            for (int j = que[i].l; j <= que[i].r; j++) {
                cmin(ans[que[i].id] , j - lef[a[j]]);
                lef[a[j]] = j;
            }
            for (int j = que[i].l; j <= que[i].r; j++)
                lef[a[j]] = -INF;
        }
    int last = -1, l, r, temp;
    for (int i = 0; i < m; i++) {
        if (que[i].r - que[i].l + 1 <= K) continue;
        if (que[i].l / K != last) {
            memset(lef, 0xc0, sizeof lef);
            memset(rig, 0x3f, sizeof rig);
            last = que[i].l / K;
            l = (last + 1) * K;
            r = l - 1; temp = INF;

        }

        cerr << que[i].l << ' ' << que[i].r << " : ";
        cerr << l << ' ' << r << '\n';

        while (r < que[i].r) {
            r++;
            cmin(temp, r - lef[a[r]]);
            lef[a[r]] = r;
            if (rig[a[r]] > n) rig[a[r]] = r;
        }
        stack<int> stk;
        ans[que[i].id] = temp;
        while (l > que[i].l) {
            stk.push(rig[a[--l]]);
            cmin(ans[que[i].id], rig[a[l]] - l);
            rig[a[l]] = l;
        }
        while (stk.size()) {
            rig[a[l]] = stk.top(); stk.pop(); l++;
        }
    }
    for (int i = 0; i < m; i++)
        if (ans[i] > n) cout << "-1\n";
        else cout << ans[i] << '\n';
}
