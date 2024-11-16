#include <bits/stdc++.h>
using namespace std;

int n, a[1001];

bool TuUoc(int n){
    int dem=0;
    for (int i=1; i<=sqrt(n); i++)
        if ( n % i == 0 ){
            dem++;
            int k=n/i;
            if ( k*k != n )
                dem++;
        }
    if (dem == 4) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    freopen("TuUoc.inp","r",stdin);
    freopen("TuUoc.out","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    int res =0;
    for (int i=1; i<=n; i++)
        if (TuUoc(a[i]))
            res++;
    cout << res;
    return 0;
}
