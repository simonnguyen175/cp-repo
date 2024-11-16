#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, k;
int a[N], d[105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    long long ans = 0;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= 100; j ++)
            if ( __gcd(a[i], j) == k )
                ans += d[j]; // so luong nhung thang truoc i ma co gia tri la j
                             // thi se tao voi j mot cap co gcd = k
        d[a[i]] ++;
    }

    cout << ans;

    return 0;
}
