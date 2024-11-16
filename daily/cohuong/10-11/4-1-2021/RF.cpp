#include <bits/stdc++.h>
#define simon "RF"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
using namespace std;
const int N=2e3+1;

int m, n;
ll a[N], b[N], P=1, Q=1;
map<ll, bool> haved;
map<ll, ll> ts[2];
vector<ll> nto;

void ptnto(int x, int k){
    if ( x == 1 ) return;
    for (int i=2; i<=sqrt(x); i++){
        int d=0;
        while ( x % i == 0 ){x/=i; d++;}
        ts[k][i]+=d;
        if ( !haved[i] ){
            nto.push_back(i);
            haved[i]=1;
        }
    }
    if ( x != 1 ){
        ts[k][x]++;
        if ( !haved[x] ){
            nto.push_back(x);
            haved[x]=1;
        }
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    /// SETUP
    cin >> m >> n;
    for (int i=1; i<=m; i++){
        cin >> a[i];
        ptnto(a[i], 0);
    }
    for (int i=1; i<=n; i++){
        cin >> b[i];
        ptnto(b[i], 1);
    }

    /// SOLVE
    for (int i=0; i<nto.size(); i++){
        int x=nto[i];
        int h=min(ts[0][x], ts[1][x]);
        ts[0][x]-=h; ts[1][x]-=h;

        if ( ts[0][x] == 0 && ts[1][x] == 0 ) continue;
        if ( ts[0][x] > 0 )
            for (int j=1; j<=ts[0][x]; j++)
                P*=x;
        else
            for (int j=1; j<=ts[1][x]; j++)
                Q*=x;
    }
    cout << P << '\n' << Q;
    return 0;
}
