#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, x;
int a[N];
long long s[N], f[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int test;
    cin >> test;
    while ( test -- ){
        cin >> n >> x;
        for (int i = 1; i <= n; i ++){
            cin >> a[i];
            s[i] = s[i-1] + a[i];
            f[i] = 0;
        }
        f[n+1] = f[n+2] = 0;

        for (int i = n; i >= 1; i --){
            int lo = i, hi = n, j = -1;
            while ( lo <= hi ){
                int mid = lo + hi >> 1;
                if ( s[mid] - s[i-1] <= x ){
                    j = mid;
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
            if ( j == -1 ) f[i] = f[i+1];
            else f[i] = f[j+2] + j - i + 1;
        }

//        for (int i = 1; i <= n; i ++)
//            cout << f[i] << ' ';
//        cout << '\n';

        long long ans = 0;
        for (int i = 1; i <= n; i ++)
            ans += f[i];
        cout << ans << '\n';
    }

    return 0;
}
