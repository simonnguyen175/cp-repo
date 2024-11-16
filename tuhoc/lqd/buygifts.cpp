#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1e5+5;

int n, m, a[N];

int main(){
    FASTio
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    sort(a+1, a+1+n);
    int ans = INT_MAX;
    for (int i=1; i<=n-m+1; i++)
         ans = min(a[i+m-1]-a[i], ans);
    cout << ans;
    return 0;
}
