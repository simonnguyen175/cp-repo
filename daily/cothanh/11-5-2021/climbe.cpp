#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;

int n;
pi a[N];

bool cmp(const pi &a, const pi &b){
    return ( a.fi + max(a.se, b.fi) + b.se < b.fi + max(b.se, a.fi) + a.se );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("climbe.inp", "r", stdin);
    freopen("climbe.ans", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i].fi;
    for (int i = 1; i <= n; i ++) cin >> a[i].se;

    sort(a + 1, a + 1 + n, cmp);

    //for (int i = 1; i <= n; i ++)  cout << a[i].fi << ' ' << a[i].se << '\n';

    int lf = 0, rt = 0;
    for (int i = 1; i <= n; i ++){
        lf += a[i].fi;
        rt = max(lf, rt) + a[i].se;
        //cout << lf << ' ' << rt << '\n';
    }

    cout << rt;

    return 0;
}
