#include <bits/stdc++.h>
using namespace std;

int n, a[1000001];

int main(){
    freopen("Increa.inp","r",stdin);
    freopen("Increa.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    int l, r;
    for (int i=1; i<=n-1; i++)
        if (a[i] > a[i+1]){
            l=i;
            break;
        }
    for (int i=n; i>=2; i--)
        if (a[i] < a[i-1]){
            r=i;
            break;
        }
    if (l >= n-1 || r <= 2){
        cout <<"Yes";
        return 0;
    }
    if (l == r-1){
        if ( a[l-1] <= a[r] ) {cout << "Yes"; return 0;}
        if ( a[r+1] >= a[l] ) {cout << "Yes"; return 0;}
    }
    cout << "No";
    return 0;
}
