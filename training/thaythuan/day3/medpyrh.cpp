#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 5;

int t, n, mx;
int b[N], a[N];
pi lef, rig;

bool check(int x){
//    cerr << x << " : \n";

    for (int i = 1; i <= 2*n - 1; i ++)
        a[i] = ( b[i] >= x );

//    for (int i = 1; i <= 2*n-1; i ++) cerr << a[i] << ' '; cerr << '\n';

    if ( n == 1 ) return a[1];

    lef = {0, 0}, rig = {0, 0};
    for (int i = n-1; i >= 2; i --)
        if ( a[i] == a[i-1] ) { lef = {a[i], i-1}; break; }

    for (int i = n-1; i <= 2*n-2; i ++)
        if ( a[i] == a[i+1] ) { rig = {a[i], i+1}; break; }

//    cerr << lef.fi << ' ' << lef.se << " and " << rig.fi << ' ' << rig.se << '\n';

    if ( !lef.se ){
        if ( !rig.se )
            return ( n % 2 ? a[n] : 1-a[n] );
        else return rig.fi;
    }
    else{
        if ( !rig.se ) return lef.fi;
        else
            if ( n - lef.se > rig.se - n )
                return rig.fi;
            else return lef.fi;
    }
}

void solve(){
    cin >> n;
    mx = 0;
    for (int i = 1; i <= 2*n-1; i ++)
        cin >> b[i], mx = max(b[i], mx);

    int lo = 1, hi = mx, res = 0;
    while ( lo <= hi ){
        int mid = lo + hi >> 1;
        if ( check(mid) ) lo = mid + 1, res = mid;
        else hi = mid - 1;
    }

    cout << res << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> t;
    while ( t -- )
        solve();

    return 0;
}
