#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
const int base = 2e6;

int n;
int a[N];
long long ans[N];
int d[(int)4e6 + 5];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int k = 1; k <= n; k ++){
        for (int x = k + 1; x <= n; x ++)
            ans[x] += d[a[x] - a[k] + base];
        for (int i = 1; i < k; i ++)
            d[a[k] + a[i] + base] ++;
    }

    for (int i = 1; i <= n; i ++)
        cout << ans[i] << ' ';

    return 0;
}
