#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
const int oo = 1e12;

int n;
int a[N];

bool check(int mid){
    int sub = 0;
    for (int i = n; i >= 2; i --) if ( 2*a[i] >= mid )
        sub += (2*a[i] - mid)/2;

    if ( sub >= mid - a[1] ) return true;
    else return false;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int test;
    cin >> test;
    while ( test -- ){
        cin >> n;
        for (int i = 1; i <= n; i ++)
            cin >> a[i];

        int lo = a[1], hi = oo, ans = a[1];
        while ( lo <= hi ){
            int mid = (lo + hi)/2;
            if ( check(mid) ){
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }

        cout << ans - a[1] << '\n';
    }

    return 0;
}
