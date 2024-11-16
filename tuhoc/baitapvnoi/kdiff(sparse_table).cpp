#include<bits/stdc++.h>
using namespace std;
const int N = 3e6 + 5;

int n, k, a[N], ans;
int stmax[N][20], stmin[N][20], Log[N];
int f[N], g[N];

int check(int l , int r){
	int Min , Max;
	int cnt = Log[r - l + 1];
    Max = max(stmax[l][cnt] , stmax[r - (1 << cnt) + 1][cnt]);
    Min = min(stmin[l][cnt] , stmin[r - (1 << cnt) + 1][cnt]);
    return Max - Min ;
}

int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    Log[1] = 0;
    for (int i = 2; i <= n; i ++)
        Log[i] = Log[i/2] + 1;

    for (int i = 1; i <= n; i ++){
        stmin[i][0]= stmax[i][0] = a[i];
    }

    for (int j = 1; j <= Log[n]; j ++)
        for (int i = 1; i + ( 1 << j ) - 1<= n; i ++){
            stmin[i][j] = min(stmin[i][j-1], stmin[i + ( 1 << (j - 1) )][j-1]);
            stmax[i][j] = max(stmax[i][j-1], stmax[i + ( 1 << (j - 1) )][j-1]);
        }


    int c = 1;
    for (int i = 1; i <= n; i ++){

        while ( c < n && check(i, c + 1) <= k ) c ++;


        g[i] = c - i + 1;
        f[c] = max (f[c], c - i + 1);
    }

    for (int i = n; i >= 1; i --)
        if ( f[i + 1] > 0 && f[i] == 0 ){
            f[i] = f[i + 1] - 1;
        }

    for (int i = 2; i <= n; i ++)
        f[i] = max(f[i-1], f[i]);

     for (int i = 1; i <= n; i ++)
        ans = max(ans, f[i-1] + g[i]);

    cout << ans;

    return 0;
}
