#include<bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int n;
ll a, b, c, w;
ll f1[25][25], f2[25][25], f3[25][25], f[25][25][25];
map<pair<int,int>, ll> d;

int BIT(int x , int k){
	return (x >> k) & 1;
}4


ll get(int id, int t2, int t3){
    if ( id == 0 ) return 0;

    if ( d.count({t2,t3}) ) return d[{t2,t3}];

    ll best = 0;

    FOR(i, 1, n) FOR(j, 1, n)
        if ( !BIT(t2,i-1) && !BIT(t3,j-1) ){
            ll tmp = a*f1[id][i] + b*f2[id][j] + c*f3[i][j] + w*f[id][i][j];
            best = max(best, tmp + get(id-1, t2|(1<<(i-1)), t3|(1<<(j-1))));
        }

    d[{t2,t3}] = best;

    return best;
}


int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
    cin >> n >> a >> b >> c >> w;
    FOR(i,1,n) FOR(j,1,n) cin >> f1[i][j];
    FOR(i,1,n) FOR(j,1,n) cin >> f2[i][j];
    FOR(i,1,n) FOR(j,1,n) cin >> f3[i][j];
    FOR(i,1,n) FOR(j,1,n) FOR(k,1,n) cin >> f[i][j][k];

    cout << get(n, 0, 0);

    return 0;
}
