#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int n;
int a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int ans = 0;
    for (int i = 2; i <= n; i ++)
        ans = max(ans, a[i] - a[i-1]);
    cout << ans;

    return 0;
}
