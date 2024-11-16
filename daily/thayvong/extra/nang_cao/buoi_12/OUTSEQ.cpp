#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
ll x, a[200001];

int main(){
    freopen("OUTSEQ.inp","r",stdin);
    freopen("OUTSEQ.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    x=0;
    sort(a+1,a+1+n);
    for (int i=1; i<=n; i++)
        if ( a[i] <= x+1 ) x=a[i]+x;
        else{ cout << x+1; return 0;}
    cout << x+1;
    return 0;
}
