#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define simon "CheckMonoSeq"
using namespace std;
const int N = 1e2 + 5;

int t, n, a[N], b[N];

bool check(){
    for (int i = 1; i <= n; i ++)
        b[i] = a[i];
    sort(b+1, b+1+n);

    int cnt, tmp = 0;
    for (int i = 1; i <= n ; i ++)
        if ( b[i] != a[i] ) tmp ++;
    cnt = tmp;

    sort(b+1, b+1+n, greater<int>());
    tmp = 0;
    for (int i = 1; i <= n; i ++)
        if ( b[i] != a[i] ) tmp ++;
    cnt = min(cnt, tmp);

    if ( cnt <= 2 ) return true;
    else return false;
}

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> t;
    while ( t -- ){
        cin >> n;
        for (int i = 1; i <= n; i ++)
            cin >> a[i];
        cout << check() << '\n';
    }
}
