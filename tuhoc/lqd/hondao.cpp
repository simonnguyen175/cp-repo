#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1e6+5;

int n, a[N], b[N], low=0, ans=0;

int main(){
    FASTio
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    int m=0;
    for (int i=1; i<=n; i++){
        while ( a[i] == a[i+1] ) i++;
        b[++m]=a[i];
    }

    bool check=0;
    for (int i=2; i<=m; i++)
        if ( b[i] < b[i-1] && b[i] < b[i+1] ){
            check=1;
            low=max(low, b[i]);
        }

    if ( !check ) {cout << 1; return 0;}

    for (int i=1; i<=m; i++)
        b[i] = b[i] - low > 0 ? b[i] - low : 0;

    for (int i=1; i<=m; i++)
        if ( b[i] > 0 ){
            ans++;
            while ( b[i] > 0 ) i++;
        }
        else continue;

    cout << ans;
    return 0;
}
