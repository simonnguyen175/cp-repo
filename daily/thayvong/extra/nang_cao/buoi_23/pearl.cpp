#include<bits/stdc++.h>
#define simon "Pearl"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=5e5+5;

int n, m=0, a[N];
int divisor[N];
pair<int, int> d[N];
int pre[N];

void init(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        d[i].first = a[i];
        d[i].second = i;
    }
    sort(d+1, d+1+n);
    for (int i=2; i<=n; i++)
        if ( d[i].first == d[i-1].first ) pre[d[i].second] = d[i-1].second;
        else continue;

    for (int i=1; i*i<=n; i++)
        if ( n % i == 0 ){
            if ( (n/i)*(n/i) != n ){
                divisor[++m] = n/i;
                divisor[++m] = i;
            }
            else divisor[++m] = i;
        }
}

void solve(int u){
    int i=1, res=INT_MAX;
    while ( i <= n ){
        int l = i, r = i + u - 1, spc=0;
        for (int j=l; j<=r; j++){
            if ( pre[j] >= l && pre[j] <= r ) continue;
            else
                spc++;
        }
        i = r + 1;
        res = min(res, spc);
    }

    cout << u <<' '<<res <<'\n';
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    init();
    sort(divisor+1, divisor+1+m);
    cout << m <<'\n';
    for (int i=1; i<=m; i++)
        solve(divisor[i]);
    return 0;
}
