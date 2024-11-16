#include<bits/stdc++.h>
using namespace std;
const int N = 3e3 + 5;

int r, c, h, w, ans;
int a[N][N], s[N][N];

bool check(int med){
    memset(s, 0, sizeof s);

    int cost = 0;
    for (int i = 1; i <= r; i ++)
    for (int j = 1; j <= c; j ++){
        if ( a[i][j] < med ) cost = 1;
        s[i][j] = cost + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
        cost = 0;
    }

    for (int i = 1; i + h - 1 <= r; i ++)
    for (int j = 1; j + w - 1 <= c; j ++)
        if ( s[i+h-1][j+w-1] - s[i-1][j+w-1] - s[i+h-1][j-1] + s[i-1][j-1] <= h * w / 2 )
            return true;

    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> r >> c >> h >> w;
    for (int i = 1; i <= r; i ++)
        for (int j = 1; j <= c; j ++)
            cin >> a[i][j];

    int lo = 1, hi = r * c;

    while ( lo <= hi ){
        int mid = ( lo + hi ) >> 1;
        if ( check(mid) ) ans = mid, lo = mid + 1;
        else hi = mid - 1;
    }

    cout << ans;

    return 0;
}
