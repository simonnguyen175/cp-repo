#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;

int n;
int d[N], w[N], mn[N][20];

int get(int l, int r){
    int k = __lg(r-l+1);
    if ( w[mn[l][k]] < w[mn[r-(1<<k)+1][k]] ) return mn[l][k];
    else return mn[r-(1<<k)+1][k];
}

int calc(int l, int r, int pre){
    if ( l > r ) return 0;
    if ( l == r ) return w[l] > pre;
    int mid = get(l, r);
    return calc(l, mid-1, w[mid]) + calc(mid+1, r, w[mid]) + ( w[mid] > pre );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("poster.inp", "r", stdin);
    freopen("poster.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> d[i] >> w[i];
        mn[i][0] = i;
    }

    for (int j = 1; j <= __lg(n); j ++)
    for (int i = 1; i <= n-(1<<j)+1; i ++)
        if ( w[mn[i][j-1]] < w[mn[i+(1<<(j-1))][j-1]] )
            mn[i][j] = mn[i][j-1];
        else mn[i][j] = mn[i+(1<<(j-1))][j-1];

    cout << calc(1, n, 0);

    return 0;
}
