#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;

int n, k;
int a[N];

bool check(int diff){
    int res = 0;
    int j = n / 2;
    for (int i = n; i > n / 2; i --){
        if ( j == 0 ) break;
        if ( a[i] - a[j] < diff ){
            while ( a[i] - a[j] < diff && j >= 1 ) j --;
            if ( j == 0 ) break;
            res ++;
            j --;
        }
        else {res ++; j --;}
    }

    return ( res >= k );
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);

    int lo = 0, hi = 1e9, res;

    while ( lo <= hi ){
        int mid = ( lo + hi ) / 2;
        if ( check(mid) ){
            res = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }

    cout << res;

    return 0;
}
