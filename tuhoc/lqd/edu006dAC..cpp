#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 5;
const int oo = 1e8;

int n;
pair<int, int> a[N];
int pre[N], suf[N];

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
    pre[0] = -oo;
    for (int i = 1; i <= n; i ++)
        pre[i] = max(pre[i-1], a[i].fi + n - i + 1);
    suf[n+1] = -oo;
    for (int i = n; i >= 1; i --)
        suf[i] = max(suf[i+1], a[i].fi + n - i + 1);

    for (int i = 1; i <= n; i ++){
        if ( pre[i-1] - 1 <= a[i].fi + n && suf[i+1] <= a[i].fi + n )
            ans.push_back(a[i].se);
    }

//    sort(ans.begin(), ans.end());
//    cout << ans.size() << '\n';
//    for (auto x : ans) cout << x << ' ';

    return 0;
}

