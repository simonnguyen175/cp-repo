#include<bits/stdc++.h>
#define simon "dolls"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e5 + 5;

int n, k;
int a[N];
multiset<int> cont;
map<int, int> d;

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> a[i]; d[a[i]] ++;
        cont.insert(a[i]);
    }

    sort(a + 1, a + 1 + n);

    long long ans = 0;

    for (int i = n; i >= 1; i --) if ( d[a[i]] ){
        ans += a[i];
        int par = a[i]; d[a[i]] --;
        //cout << par << ' ';
        while ( true ){
            if ( par - k < 0 ) break;
            auto it = cont.upper_bound(par - k);
            if ( it == cont.begin() ) break;

            it --;
            par = *it; d[par] --;
            //cout << par << ' ';
            cont.erase(it);
        }
        //cout << '\n';
    }

    cout << ans;
}
