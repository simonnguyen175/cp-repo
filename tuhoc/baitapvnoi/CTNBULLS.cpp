#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 2111992
ll n, k, f[100001];

int main(){
    cin >> n >> k;
    for (int i=1; i<=k+1; i++)
        f[i]=i+1;
    for (int i=k+2; i<=n; i++){
        f[i]=f[i-1]+f[i-k-1];
        f[i]%=MOD;
    }
    cout << f[n];
    return 0;
}
