#include <bits/stdc++.h>
using namespace std;
const int N=2e5+1;

int n, k, a[N], xk;
long long ans=0;
map<int, int> b;

int main(){
    freopen("KArrAtLeast.inp","r",stdin);
    freopen("KArrAtLeast.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
    cin >> n >> k;

    for (int i=1; i<=n; i++)
        cin >> a[i];

    int i=1, xk=0;
    for (int j=1; j<=n; j++){
        b[a[j]]++;
        if ( b[a[j]] == 1 ) xk++;
        while ( k == xk ){
            ans=ans + ( n - j + 1 );
            b[a[i]]--;
            if ( b[a[i]] == 0 ) xk--;
            i++;
        }
    }
    cout << ans;
    return 0;
}
