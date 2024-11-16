#include<bits/stdc++.h>
#define simon "wmt"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e3 + 5;

int n, m;
int a[N][N];
long long s[N][N];

pair<int, int> getMedian(int a[], int b[]){
    int l = 1, r = n, half = n, len = 2 * n;
    while ( l <= r ){
        int i = ( l + r ) / 2;
        int j = half - i;

        if ( b[j] > a[i+1] ) l = i + 1;
        else if ( b[j+1] < a[i] ) r = i - 1;
        else{
            return {i, j};
        }
    }
}

int main(){
    FASTio
    if ( fopen("wmt.inp", "r") ){
        freopen("wmt.inp", "r", stdin);
        freopen("wmt.out", "w", stdout);
    }
    cin >> m >> n;
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> a[i][j];
    for (int i = 1; i <= m; i ++)
        sort(a[i]+1, a[i]+1+n);
    for (int i = 1; i <= m; i ++){
        s[i][0] = 0;
        for (int j = 1; j <= n; j ++)
            s[i][j] = s[i][j-1] + a[i][j];
    }
    long long ans = 0;
    for (int i = 1; i < m; i ++){
        for (int j = i + 1; j <= m; j ++){
            pair<int, int> opt = getMedian(a[i], a[j]);
            int med = min(a[i][opt.first], a[j][opt.second]);

            ans += opt.first * med - s[i][opt.first] + s[i][n] - s[i][opt.first] - (n-opt.first) * med
                    + opt.second * med - s[j][opt.second] + s[j][n] - s[j][opt.second] - (n-opt.second) * med;
        }
    }
    cout << ans;
    return 0;
}
