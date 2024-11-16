#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, a[N], res = 0;
multiset<int> cont;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("tamgiac.inp", "r") ){
        freopen("tamgiac.inp", "r", stdin);
        freopen("tamgiac.out", "w", stdout);
    }

    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];

    int l = 1;

    for(int i = 1; i <= n; i ++){
        cont.insert(a[i]);

        if( cont.size() < 3 ) continue;

        auto it1 = cont.begin();
        auto it2 = cont.begin(); it2 ++;
        auto it3 = cont.rbegin();

        while( *it1 + *it2 <= *it3 && cont.size() >= 3 ){
            cont.erase(cont.find(a[l]));
            it1 = cont.begin();
            it2 = cont.begin(); it2 ++;
            it3 = cont.rbegin();
            l ++;
        }

        if ( cont.size() >= 3 ) res = max(res, i - l + 1);
    }

    cout << res;

    return 0;
}
