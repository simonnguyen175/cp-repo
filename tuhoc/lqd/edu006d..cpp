#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;

int n;
pair<int, int> a[N];

int main(){
    if ( fopen("vannghe.inp", "r") ){
        freopen("vannghe.inp", "r", stdin);
        freopen("vannghe.out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].fi;
        a[i].se = i;
    }

    vector<int> ans;
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i ++){
        bool ck = 1;
        int tt = n - 1;
        for (int j = 1; j <= n; j ++) if ( j != i ){
            if ( a[j].fi + tt > a[i].fi + n )
                { ck = 0; break; }
            tt --;
        }
        if ( ck ) ans.push_back(a[i].se);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << ' ';

    return 0;
}
