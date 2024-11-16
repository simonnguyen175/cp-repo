#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int t, n, a[N];
ll s[N], f[N], last[N];

int tknp(int l, int r, int id){
    int d = l, c = r, res = r + 1;

    while ( d <= c ){
        int mid = ( d + c ) / 2;
        if ( s[mid] - s[id] >= last[id] ){
            res = mid;
            c = mid - 1;
        }
        else d = mid + 1;
    }

    return res;
}

int main(){
    freopen("mergesort.inp", "r", stdin);
    freopen("mergesort.out", "w", stdout);
    cin >> t;
    while ( t -- ){
        cin >> n;

        s[0] = 0;
        for (int i = 1; i <= n; i ++)
            cin >> a[i], s[i] = s[i-1] + a[i];

        for (int i = 1; i <= n; i ++)
            f[i] = 1, last[i] = s[i];

        for (int i = 1; i <= n; i ++){
            if ( f[i-1] > f[i] ){
                f[i] = f[i-1];
                last[i] = last[i-1] + a[i];
            }
            else if ( f[i-1] == f[i] ) last[i] = min(last[i], last[i-1] + a[i]);

            int j = tknp(i+1, n, i);

            if ( f[i] + 1 > f[j] ){
                f[j] = f[i] + 1;
                last[j] = s[j] - s[i];
            }
            else if ( f[i] + 1 == f[j] ) last[j] = min(last[j], s[j] - s[i]);
        }

        cout << n - f[n] << '\n';
    }

    return 0;
}
