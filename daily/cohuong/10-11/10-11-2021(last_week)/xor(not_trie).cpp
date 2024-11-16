#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int t, n;
int a[N];

void solve(){
    int mx = 0, mask = 0;
    set<int> cont;
    for (int i = 30; i >= 0; i --){
        mask |= (1<<i);
        set<int> cont;
        for (int i = 1; i <= n; i ++)
            cont.insert(a[i]&mask);
        int nmx = mx | (1<<i);
        for (int pre : cont)
            if ( cont.count(nmx^pre) ){
                mx = nmx;
                break;
            }
    }
    cout << mx << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("xor.inp", "r", stdin);
    freopen("xor.out", "w", stdout);

    cin >> t;
    while ( t -- ){
        cin >> n;
        for (int i = 1; i <= n; i ++)
            cin >> a[i];
        solve();
    }
    return 0;
}
