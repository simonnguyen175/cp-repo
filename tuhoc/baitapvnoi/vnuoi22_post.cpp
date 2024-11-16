#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n;
int x[N], f[N], mn[N][22], mx[N][22];

int getmx(int l, int r){
    int k = __lg(r-l+1);
    return max(mx[l][k], mx[r-(1<<k)+1][k]);
}

int getmn(int l, int r){
    int k = __lg(r-l+1);
    return min(mn[l][k], mn[r-(1<<k)+1][k]);
}

bool check(int d){
    for (int i = 1; i <= n; i ++) f[i] = 0;
    f[2] ++; f[3] --;
    for (int i = 2; i <= n; i ++){
        f[i] += f[i-1];
        if ( !f[i] ) continue;
        int lo = i-1, hi = n, pos = i-1;
        while ( lo <= hi ){
            int mid = lo + hi >> 1;
            if ( abs(getmx(i-1, mid) - x[i-1]) <= d
              && abs(getmn(i-1, mid) - x[i-1]) <= d )
                pos = mid, lo = mid + 1;
            else hi = mid - 1;
        }
        if ( pos == n ) return 1;
        pos ++;
        f[i+1] ++;
        f[pos+1] --;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    n += 2;
    for (int i = 1; i <= n; i ++){
        cin >> x[i];
        mn[i][0] = mx[i][0] = x[i];
    }

    for (int j = 1; j <= 20; j ++)
    for (int i = 1; i <= n-(1<<j)+1; i ++){
        mx[i][j] = max(mx[i][j-1], mx[i+(1<<(j-1))][j-1]);
        mn[i][j] = min(mn[i][j-1], mn[i+(1<<(j-1))][j-1]);
    }

    int lo = abs(x[1]-x[2]), hi = 1e9, res;
    while ( lo <= hi ){
        int mid = lo + hi >> 1;
        if ( check(mid) ) res = mid, hi = mid - 1;
        else lo = mid + 1;
    }

    cout << res;

    return 0;
}
