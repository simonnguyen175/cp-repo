#include<bits/stdc++.h>
#define BIT(x, k) ((x>>k)&1)
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e3 + 5;

int t, n;
pi a[N];

bool compare(pi a, pi b){
    for (int i = 0; i <= 10; i ++)
        if ( BIT(a.fi, i) != BIT(b.fi, i) )
            return BIT(a.fi, i);
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> t;
    while ( t -- ){
        cin >> n;
        for (int i = 1; i <= n; i ++)
            cin >> a[i].fi, a[i].se = i;
        sort(a+1, a+1+n, compare);
        for (int i = 1; i <= n; i ++)
            cout << a[i].se << ' ';
        cout << '\n';
    }

    return 0;
}
