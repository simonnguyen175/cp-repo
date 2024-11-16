#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n;
double a[N], b[N], sa[N], sb[N];

double calc(int i, int j){
    return min(sa[i] - j, sb[j] - i);
}

int main(){
    freopen("taixiu.inp", "r", stdin);
    freopen("taixiu.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }

    sort(a + 1, a + 1 + n, greater<double>());
    sort(b + 1, b + 1 + n, greater<double>());


    for (int i = 1; i <= n; i ++) sa[i] = sa[i-1] + a[i];
    for (int i = 1; i <= n; i ++) sb[i] = sb[i-1] + b[i];

    double ans;

    for (int i = 0; i <= n; i ++){
        int d = 0, c = n;
        double res = -1e15, A, B;
        while ( d <= c ){
            int mid = ( d + c ) / 2;

            A = sa[i] - mid;
            B = sb[mid] - i;

            res = max(res, min(A, B));

            if ( A == B ) break;

            if ( A > B ) d = mid + 1;
            else c = mid - 1;

        }
        ans = max(ans, res);
    }

    cout << fixed << setprecision(4) << ans;

    return 0;
}
