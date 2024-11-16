#include<bits/stdc++.h>
using namespace std;

int n, k;
int a[20], sum[1<<12], f[1<<12];

bool check(int x){
    for (int i = 1; i < (1<<n); i ++) f[i] = 1e9;
    for (int i = 1; i < (1<<n); i ++){
        for (int j = i; j > 0; j = (j-1)&i)
            if ( sum[j] <= x )
                f[i] = min(f[i], f[i^j]+1);
    }
    return f[(1<<n)-1] <= k;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    int s = 0;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        s += a[i];
    }

    for (int i = 1; i < (1<<n); i ++)
        for (int j = 0; j < n; j ++)
            if ( i&(1<<j) ) sum[i] += a[j+1];

    int lo = 1, hi = s, res;
    while ( lo <= hi ){
        int mid = lo + hi >> 1;
        if ( check(mid) ) res = mid, hi = mid - 1;
        else lo = mid + 1;
    }
    cout << res;

    return 0;
}
