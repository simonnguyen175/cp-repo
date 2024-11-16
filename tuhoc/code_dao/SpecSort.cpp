#include<bits/stdc++.h>
using namespace std;

int n;
int a[100005];
multiset<int> setb, setc;

int main(){
    if ( fopen("SpecSort.inp", "r") ){
        freopen("SpecSort.inp", "r", stdin);
        freopen("SpecSort.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++){
        int x; cin >> x; setb.insert(x);
    }
    for (int i = 1; i <= n; i ++){
        int x; cin >> x; setc.insert(x);
    }
    sort(a + 1, a + 1 + n);

    int ans = 0;

    for (int i = 1; i <= n; i ++){
        auto it1 = setb.upper_bound(a[i]);
        auto it2 = setc.upper_bound(*it1);
        if ( it1 != setb.end() && it2 != setc.end() ){
            ans ++;
            setb.erase(it1);
            setc.erase(it2);
        }
        else break;
    }

    cout << ans;

    return 0;
}
