#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, a[N], b[N], f[N];

int tknp(int l, int r, int x){
    int d = l, c = r, res = 0;
    while ( d <= c ){
        int mid = (d+c)/2;
        if ( b[mid] < x ){
            res = mid;
            d = mid + 1;
        }
        else c = mid - 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    int ans = 0;
    for (int i = 1; i <= n; i ++){
        int len = tknp(1, ans, a[i]);
        f[i] = len + 1;
        ans = max(ans, f[i]);
        b[f[i]] = a[i];
    }

    cout << n - ans;
    return 0;
}
