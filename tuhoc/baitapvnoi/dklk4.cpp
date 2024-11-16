#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, k;
int a[N];
long long s[N];

bool check(int mid){
    for (int i = mid; i <= n; i ++)
        if ( s[i] - s[i-mid] > k ) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], s[i] = s[i-1] + a[i];

    int l = 1, r = n, ans = -1;
    while ( l <= r ){
        int mid = l + r >> 1;
        if ( check(mid) ){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << ans;

    return 0;
}
