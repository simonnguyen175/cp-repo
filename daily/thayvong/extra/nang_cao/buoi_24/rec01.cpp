#include<bits/stdc++.h>
#define simon "rec01"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e3+5;

int r, c, a[N][N], far[N][N], ans = 0;

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> r >> c;
    for (int i=1; i<=r; i++)
        for (int j=1; j<=c; j++)
            cin >> a[i][j];

    for (int i=1; i<=c; i++){
        int len = 0;
        for (int j=1; j<=r; j++){
            if ( a[j][i] == 0 ){
                len = 0;
                continue;
            }
            len++;
            far[i][j] = len;
            //cout << i << ' ' << j <<' '<<far[i][j] << '\n';
        }
    }

    /*
    cout << '\n';
    for (int i=1; i<=c; i++){
        cout << "cot" << i << '\n';
        for (int j=1; j<=r; j++)
            cout << far[i][j] <<' ';
        cout <<'\n';
    }
    cout << '\n';
    */

    for (int i=1; i<=r; i++){
        vector<int> h;
        for (int j=1; j<=c; j++)
            if ( far[j][i] > 0 )
                h.push_back(far[j][i]);

        sort(h.begin(), h.end());
        int n = h.size();
        for (int i=0; i<n; i++)
            ans = max(ans, h[i]*(n-i) );
    }

    cout << ans;
    return 0;
}
