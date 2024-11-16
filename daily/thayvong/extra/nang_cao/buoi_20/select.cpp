#include <bits/stdc++.h>
#define simon "select"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define cc pair<char, char>
using namespace std;
const int N=1e5+1;
const ll oo=1e15;

int n, a[5][N];
ll f[N][20];

int sum(int i, int mask){
    int s=0;
    bitset<4> b(mask);
    for (int t=0; t<=3; t++){
        if (b[t]) s+=a[t][i];
    }
    return s;
}

bool check(int mask){
    bitset<4> b(mask);
    for (int i=1; i<=3; i++)
        if ( b[i] == 1 && b[i-1] == 1 )
            return false;
    return true;
}

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> n;
    int MAX=INT_MIN;
    for (int i=0; i<=3; i++)
        for (int j=1; j<=n; j++){
            cin >> a[i][j];
            MAX=max(a[i][j], MAX);
        }
    for (int i=1; i<=n; i++)
        for (int mask1=0; mask1<=10; mask1++)
            for (int mask2=0; mask2<=10; mask2++)
                if ( check( mask1 ) && check( mask2 ) ){
                    int e = mask1 & mask2;
                    if ( e == 0 )
                        f[i][mask1] = max(f[i][mask1], sum(i, mask1) + f[i-1][mask2]);
                }

    ll ans=-oo;
    for (int i=0; i<=10; i++)
        ans=max(ans, f[n][i]);
    if ( ans == 0 ) cout << MAX;
    else cout << ans;
    return 0;
}
