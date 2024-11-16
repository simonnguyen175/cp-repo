#include<bits/stdc++.h>
#define simon "grn"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e6 + 5;

int n;
long long a[2*N];
map<long long, int> d;

bool check(int diff){
    map<int, int> used;
    for (int i = 1; i <= n; i ++){
        if ( used[a[i]] ) continue;
        if ( !d[a[i]+diff] ) return false;
        else used[a[i]+diff] = 1;
    }
    return true;
}

bool checklt(){
    for (int i = 1; i < n; i ++)
        if ( a[i+1] != a[i] + 1 ) return false;
    return true;
}

int souoc(int x){
    int res = 0;
    for (int i = 1; i <= sqrt(x); i ++)
        if ( x % i == 0 )
            if ( i != (x/i) ) res += 2;
            else res += 1;
    return res;
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n; n *= 2;
    for (int i = 1; i <= n; i ++) cin >> a[i];

    if ( n <= 2000 ){
        for (int i = 1; i <= n; i ++)  d[a[i]] = 1;

        sort(a + 1, a + 1 + n);

        int ans = 0;
        for (int i = 2; i <= n; i ++){
            int diff = a[i] - a[1];
            if ( check(diff) ) ans ++;
        }

        cout << ans;
    }
    else cout << souoc(n/2);

    return 0;
}
