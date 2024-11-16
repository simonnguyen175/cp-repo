#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 2e5 + 5;

int n, t;
int a[N], b[N], c[N];
vector<int> cont;

int id(int x){
    return upper_bound(cont.begin(), cont.end(), x) - cont.begin();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("dlight.inp", "r") ){
        freopen("dlight.inp", "r", stdin);
        freopen("dlight.out", "w", stdout);
    }

    cin >> n >> t;
    for (int i = 1; i <= t; i ++){
        cin >> a[i] >> b[i];
        cont.pb(a[i]);
        cont.pb(b[i]+1);
    }
    cont.pb(1), cont.pb(n);
    sort(cont.begin(), cont.end());
    cont.erase(unique(cont.begin(), cont.end()), cont.end());

    for (int i = 1; i <= t; i ++){
        c[id(a[i])] ++,
        c[id(b[i]+1)] --;
    }

    int ans = 0;
    for (int i = 1; i <= cont.size(); i ++){
        if ( cont[i-1] > n ) break;
        c[i] += c[i-1];
        if ( c[i] % 3 == 0 )
            ans += ( i == cont.size() ? 1 : cont[i] - cont[i-1] );
    }

    cout << ans;

    return 0;
}
