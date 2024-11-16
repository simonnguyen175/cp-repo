#include <bits/stdc++.h>
using namespace std;

int n, a[1001], b[1001];

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=n; i++)
        cin >> b[i];
    for (int i=1; i<=n; i++)
        if ( a[i] > b[i] )
            swap(a[i],b[i]);
    for (int i=1; i<=n; i++)
        cout << a[i] <<" ";
    cout <<"\n";
    for (int i=1; i<=n; i++)
        cout << b[i] <<" ";
    return 0;
}
