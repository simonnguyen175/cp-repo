#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int oo = 2e9;

int n;
int a[N], mn[N], mx[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i ++) mx[i] = 0, mn[i] = oo;
    for (int i = (n+1)/2; i >= 1; i --){
        mx[i] = max(mx[i+1], a[n-i+2]+a[i]);
        mn[i] = min(mn[i+1], a[n-i+2]+a[i]);
    }
    int cmx = 0, cmn = oo, ans = oo;
    for (int i = 1; i <= (n+1)/2; i ++){
        int tmx = max(cmx, mx[i+1]);
        int tmn = min(cmn, mn[i+1]);
//        cerr << i << ' ' << tmx << ' ' << tmn << '\n';
        ans = min(ans, tmx-tmn);
        cmx = max(cmx, a[n-i+1]+a[i]);
        cmn = min(cmn, a[n-i+1]+a[i]);
    }

    for (int i = 1; i <= n; i ++) mx[i] = 0, mn[i] = oo;
    for (int i = (n+1)/2; i <= n; i ++){
        mx[i] = max(mx[i-1], a[i]+a[n-i]);
        mn[i] = min(mn[i-1], a[i]+a[n-i]);
    }
    cmx = 0, cmn = oo;
    for (int i = n; i >= n/2+2; i --){
        int tmx = max(cmx, mx[i-1]);
        int tmn = min(cmn, mn[i-1]);
        ans = min(ans, tmx-tmn);
        cmx = max(cmx, a[i]+a[n-i+1]);
        cmn = min(cmn, a[i]+a[n-i+1]);
    }

    cout << ans;

    return 0;
}
