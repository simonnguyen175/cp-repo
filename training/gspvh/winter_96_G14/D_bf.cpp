#include<bits/stdc++.h>
#define simon "photos"
#define ll long long
using namespace std;
const int MOD = 998244353;

int n, m;
int a[1005];
vector<int> cont;

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

//    if ( fopen(simon".inp", "r") ){
//        freopen(simon".inp", "r", stdin);
//        freopen(simon".out", "w", stdout);
//    }

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 1; i <= n; i ++)
    for (int j = i+1; j <= n; j ++)
        cont.push_back(a[i]^a[j]);

    sort(cont.begin(), cont.end(), greater<int>());
    ll ans = 0;
    for (int i = 0; i < m; i ++)
        ans = add(ans, cont[i]);
    cout << ans;

    return 0;
}
