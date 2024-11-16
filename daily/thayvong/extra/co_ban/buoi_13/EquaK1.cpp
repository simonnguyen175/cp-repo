#include <bits/stdc++.h>
using namespace std;

long long n,k,a[100001];
long long res=0;

int main(){
    cin >> n >> k;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=n; i++){
        if (a[i]==k) res++;
    }
    cout << res;
    return 0;
}
