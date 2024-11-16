#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m;
vector<int> a;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("grab.inp", "r") ){
        freopen("grab.inp", "r", stdin);
        freopen("grab.out", "w", stdout);
    }

    cin >> n >> m;
    if ( n == 0 ) { cout << 0; return 0; }

    a.resize(n);
    for (int i = 0; i < n; i ++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int pre = 0, suf, ans = (int)1e9;
    for (int i = 0; i < a.size(); i ++){
        auto it = upper_bound(a.begin(), a.end(), a[i] + n - 1);
        suf = a.end() - it;
        ans = min(ans, pre + suf);
        pre ++;
    }

    cout << ans;

    return 0;
}
