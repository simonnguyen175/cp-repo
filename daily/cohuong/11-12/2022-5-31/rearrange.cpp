#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define BIT(x,k) ((x>>k)&1)
using namespace std;

ll n;
int m;
int dd[10];
ll f[1<<19][101];
vector<int> a;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("rearrange.in", "r") ){
        freopen("rearrange.in", "r", stdin);
        freopen("rearrange.out", "w", stdout);
    }

    cin >> n >> m;
    while ( n ){
        a.pb(n%10);
        n /= 10;
    }
    reverse(a.begin(), a.end());
    n = a.size();

    f[0][0] = 1;

    int tt = 0;
    for (int t = 0; t < (1<<n); t ++)
    for (int d = 0; d < m; d ++) if ( f[t][d] ){
        tt ++;
        for (int i = 0; i < n; i ++){
            if ( ( !t && !a[i] ) || BIT(t, i) || dd[a[i]] == tt ) continue;
            f[t|(1<<i)][(d*10+a[i])%m] += f[t][d];
            dd[a[i]] = tt;
        }
    }

    cout << f[(1<<n)-1][0];

    return 0;
}
