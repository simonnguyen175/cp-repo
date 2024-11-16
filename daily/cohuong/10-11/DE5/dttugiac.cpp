#include<bits/stdc++.h>
#define pi pair<int, int>
#define x first
#define y second
using namespace std;
const int N = 3e3 + 5;

int n;
pi a[N];
double ans = 0.0;

double stg(pi a, pi b, pi c){
    return abs( (1.0*(b.x-a.x)*(c.y-a.y) - 1.0*(c.x-a.x)*(b.y-a.y)) / 2 );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("poly.inp", "r") ){
        freopen("poly.inp", "r", stdin);
        freopen("poly.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].x >> a[i].y;
        a[i+n] = a[i];
    }

    for (int i = 1; i <= n; i ++)
    for (int j = i + 1; j <= n; j ++){
        int lo = i + 1, hi = j - 1;
        double res1 = 0.0;

        while ( lo <= hi ){
            int mid = lo + hi >> 1;
            if ( stg(a[i], a[mid], a[j]) < stg(a[i], a[mid+1], a[j]) ){
                res1 = stg(a[i], a[mid+1], a[j]);
                lo = mid + 1;
            }
            else res1 = stg(a[i], a[mid], a[j]), hi = mid - 1;
        }


        lo = j + 1, hi = j + n - ( j - i + 1 );
        double res2 = 0.0;
        while ( lo <= hi ){
            int mid = lo + hi >> 1;
            if ( stg(a[i], a[mid], a[j]) < stg(a[i], a[mid+1], a[j]) ){
                res2 = stg(a[i], a[mid+1], a[j]);
                lo = mid + 1;
            }
            else res2 = stg(a[i], a[mid], a[j]), hi = mid - 1;
        }

        ans = max(ans, res1 + res2);
    }

    cout << fixed << setprecision(1) << ans;

    return 0;
}
