#include<bits/stdc++.h>
#define simon "sorting"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 5e5 + 5;

int n;
int a[N], b[N];

bool check(int gap){
    for (int i = 1; i <= n; i ++) b[i] = a[i];
    bool res, ok;
    do{
        ok = 1;
        for (int i = 1; i <= n - gap; i ++)
        if ( b[i] > b[i+gap] ){
            swap(b[i], b[i+gap]);
            ok = 0;
        }
    }while ( !ok );

    for (int i = 1; i < n; i ++)
        if ( b[i] > b[i+1] ) return false;
    return true;
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    vector<int> ans;
    for (int x = 1; x <= n; x ++)
        if ( check(x) ) ans.push_back(x);

    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << ' ';
    return 0;
}
