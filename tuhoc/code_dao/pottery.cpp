#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int t, n, m;
int a[N], b[N];

long long calc(int t, int a[], int n){
    long long res = 0;
    for (int i = 1; i <= n; i ++)
        res += t / a[i];
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> t;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i ++){
        cin >> b[i];
    }

    int lo = 0, hi = t, ans = -1;
    while ( lo <= hi ){
        int mid = lo + hi >> 1;
        long long ca = calc(mid, a, n);
        long long cb = calc(t-mid, b, m);

        if ( ca <= cb ){
            ans = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }

    long long anss = min(calc(ans, a, n), calc(t-ans, b, m));
    if ( ans < t )
        anss = max(anss,
                   min(calc(ans+1, a, n), calc(t-ans-1, b, m)));
    cout << anss;


    return 0;
}
