#include <bits/stdc++.h>
using namespace std;

int n, a[1000];
int ans = INT_MIN;

int main(){
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=n-2; i++)
        for (int j=i+2; j<=n-1; j++)
            for (int k=j+2;k<=n; k++)
                ans = max(ans,a[i]+a[j]+a[k]);
    cout << ans ;
    return 0;
}
