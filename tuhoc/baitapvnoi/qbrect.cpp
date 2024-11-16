#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3 + 5;

int m, n;

int main(){
    cin >> m >> n;
    int ans = 0;
    int f[N], l[N], r[N];
    for (int i = 1; i <= m; i ++){
        for (int j = 1; j <= n; j ++) {
            int a; cin >> a;
            if (a == 0) f[j] = 0;
            else f[j] += 1;
        }

        vector<int> q;

        for (int j = 1; j <= n; j ++) {
            while (!q.empty() && f[q.back()] >= f[j]) q.pop_back();

            if ( q.empty() ) l[j] = 0;
            else l[j] = q.back();

            q.push_back(j);
        }

        q.clear();
        for (int j=n; j >= 1; j --) {
            while (!q.empty() && f[q.back()] >= f[j]) q.pop_back();

            if (q.empty()) r[j] = n + 1;
            else r[j] = q.back();

            q.push_back(j);
        }

        for (int j = 1; j <= n; j++) {
            ans = max(ans, f[j]*(r[j]-l[j]-1));
        }
    }

    cout << ans;
    return 0;
}
