#include<bits/stdc++.h>
#define simon "sub"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int n, k;
ll a[N];
map<ll, int> d;

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    set<ll> cont;
    for (int i = 1; i <= n; i ++){
        d[a[i]] ++;
        if ( d[a[i]] > 1 )
            cont.erase(a[i]);
        else if ( d[a[i]] == 1 )
            cont.insert(a[i]);

        if ( i >= k ){
            d[a[i-k]] --;
            if ( d[a[i-k]] == 1 ) cont.insert(a[i-k]);
            if ( d[a[i-k]] == 0 ) cont.erase(a[i-k]);
            if ( !cont.size() ) cout << "Nothing\n";
            else cout << *cont.rbegin() << '\n';
        }
    }

    return 0;
}
