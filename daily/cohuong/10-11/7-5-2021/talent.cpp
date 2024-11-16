#include<bits/stdc++.h>
#define simon "talent"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;

long long n, m;
pair<ll, ll> a[N], p[N];
ll conv[N], sw[N], res[N];

void file(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
}

int main(){
    file();
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> a[i].fi;
    for (int i = 1; i <= n; i ++) cin >> a[i].se;
    for (int i = 1; i <= m; i ++){
        cin >> p[i].fi;
        p[i].se = i;
    }

    sort(a + 1, a + 1 + n);
    sort(p + 1, p + 1 + m);

    sw[0] = 0;
    for (int i = 1; i <= n; i ++){
        conv[i] = conv[i-1] + a[i].fi * a[i].se;
        sw[i] = sw[i-1] + a[i].se;
    }

    int j = 1;
    for (int i = 1; i <= m; i ++){
        while ( a[j].fi <= p[i].fi && j <= n ) j ++;
        res[p[i].se] = p[i].fi * sw[j-1]  - conv[j-1] + conv[n] - conv[j-1] - ( sw[n] - sw[j-1] ) * p[i].fi;
    }

    for (int i = 1; i <= m; i ++)
        cout << res[i] << '\n';

    return 0;
}
