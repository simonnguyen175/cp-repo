#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[10000];
int ans= 0;

int main(){
    cin >> n >> k;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<n; i++)
    for (int j=i+1; j<=n; j++){
        if (a[i]+a[j]==k)
            ans++;
    }
    cout << ans;
    return 0;
}
