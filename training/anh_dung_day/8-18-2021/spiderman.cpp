#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 5;

int n, k;
pair<int, int> a[N];
int f[N], d[N];

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.se < b.se;
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].fi;
        a[i].se = i;
        d[a[i].fi] ++;
    }
    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i ++)
        if ( a[i].fi != a[i+1].fi ){
            if ( a[i].fi == k ) f[a[i].fi] += n-i;

            if ( k >= a[i].fi ) continue;

            int j = 1, t = a[i].fi;
            while ( t*j+k <= 1000000 ){
                if ( t*j+k == a[i].fi ) { f[t*j+k] += d[a[i].fi] - 1; j ++; continue; }
                f[t*j+k] += d[a[i].fi];
                j ++;
            }
        }

    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i ++)
        cout << f[a[i].fi] << ' ';

    return 0;
}
