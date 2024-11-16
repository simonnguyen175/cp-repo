#include<bits/stdc++.h>
#define simon "camax"
using namespace std;
const int N = 5e5 + 5;
const int MOD = 998244353;

int sub, n, k, cnt, ans;
int a[N];

void add(int &a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> sub >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        if ( a[i] <= k ) cnt ++;
    }

    multiset<int> s;
    int l = 1;
    for (int i = 1; i <= n; i ++){
        s.insert(a[i]);
        int tmp;
        while ( l <= i && *s.rbegin() > k )
            s.erase(s.find(a[l])), l ++;
        add(ans, i-l+1);
    }

    cout << ans << ' ';
    ans = 1;
    for (int i = 1; i <= cnt; i ++)
        add(ans, ans);
    add(ans, -1);
    cout << ans;

    return 0;
}
