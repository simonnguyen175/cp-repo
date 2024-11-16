#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 5e5 + 5;
const int oo = 1e9;

int n;
ll a[N], l[N], r[N], ans = 0;
vector<ll> cont;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("delete.inp", "r") ){
        freopen("delete.inp", "r", stdin);
        freopen("delete.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    a[0] = a[n+1] = oo;

    deque<int> dq; dq.pb(0);
    for (int i = 1; i <= n; i ++){
        while ( dq.size() && a[dq.back()] < a[i] )
            dq.pop_back();
        l[i] = dq.back();
        dq.push_back(i);
    }

    dq.clear(); dq.pb(n+1);
    for (int i = n; i >= 1; i --){
        while ( dq.size() && a[dq.back()] <= a[i] )
            dq.pop_back();
        r[i] = dq.back();
        dq.push_back(i);
    }

//    for (int i = 1; i <= n; i ++)
//        cout << i << ' ' << l[i] << ' ' << r[i] << '\n';

    for (int i = 1; i <= n; i ++)
        if ( l[i] == 0 || r[i] == n + 1 )
            cont.pb(a[i]);
        else ans += min(a[l[i]], a[r[i]]);

    //cout << ans << '\n';

    for (int i = 1; i < cont.size() - 1; i ++)
        ans += min(cont[i-1], cont[i+1]);

    cout << ans;

    return 0;
}
