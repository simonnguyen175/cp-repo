#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;

int m, n;
long long a[N][N], h[N], l[N], r[N];
bool b[N][N];

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> a[i][j];

    for (int i = 1; i < m; i ++)
        for (int j = 1; j < n; j ++)
            b[i][j] = ( (a[i][j] <= a[i+1][j]) && (a[i][j] <= a[i][j+1])
                        && (a[i+1][j] <= a[i+1][j+1]) && (a[i][j+1] <= a[i+1][j+1]) );
    long long int res = 1;

    for (int i = 1; i <= m; i ++){
        long long tmp = 1;
        for (int j = 2; j <= n; j ++)
            if ( a[i][j] >= a[i][j-1] ){
                tmp ++;
                res = max(res, tmp);
            }
            else tmp = 1;
    }

    for (int i = 1; i <= n; i ++){
        long long tmp = 1;
        for (int j = 2; j <= m; j ++)
            if ( a[j][i] >= a[j-1][i] ){
                tmp ++;
                res = max(res, tmp);
            }
            else tmp = 1;
    }

    memset(h, 0, sizeof h);
    memset(l, 0, sizeof l);
    memset(r, 0, sizeof r);


    for (int i = 1; i < m; i ++){
        for (int j = 1; j < n; j ++)
            if ( b[i][j] ) h[j] ++;
            else h[j] = 0;

        vector<long long> dq;

        for (int j = 1; j < n; j ++){
            while ( !dq.empty() && h[dq.back()] >= h[j] ){
                r[dq.back()] = j - 1;
                dq.pop_back();
            }

            if ( dq.empty() ) l[j] = 1;
            else l[j] = dq.back() + 1;
            dq.push_back(j);
        }

        while ( !dq.empty() ){
            r[dq.back()] = n - 1;
            dq.pop_back();
        }

        for (int j = 1; j < n; j ++){
            if ( h[j] > 0 )
                res = max(res, (h[j]+1)*(r[j]-l[j]+2));
        }
    }

    cout << res;

    return 0;
}
