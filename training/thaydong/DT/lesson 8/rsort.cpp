#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e4 + 5;

int n, cntfl;
vector<int> a, ans[N];

void Sort(vector<int> cont, int floor){
    if ( cont.size() == 1 ) return;

    cntfl = max(cntfl, floor);

    vector<int> l, r;

    for (int i = 0; i < cont.size()/2; i ++)
        l.pb(cont[i]);

    reverse(l.begin(), l.end());
    for (int x : l) ans[floor].pb(x);

    for (int i = cont.size()/2; i < cont.size(); i ++)
        r.pb(cont[i]);

    Sort(l, floor+1);
    Sort(r, floor+1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1, x; i <= n; i ++) cin >> x;
    for (int i = 1, x; i <= n; i ++) cin >> x, a.pb(x);

    Sort(a, 0);

    if ( cntfl ){
        cout << cntfl + 1 << '\n';
        for (int i = cntfl; i >= 0; i --){
            cout << ans[i].size() << ' ';
            for (int x : ans[i]) cout << x << ' ';
            cout << '\n';
        }
    }

    return 0;
}
