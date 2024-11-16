#include<bits/stdc++.h>
#define simon "maxsegment"
using namespace std;
const int oo = 1e9 + 5;
const int N = 5e5 + 5;

int sub, n, k;
int a[N], ans = -oo;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> sub >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    deque<int> dq;
    for (int i = 1; i <= n; i ++){
        while ( dq.size() && a[dq.back()] <= a[i] ) dq.pop_back();
        while ( dq.size() && dq.front() <= i-k ) dq.pop_front();
        dq.push_back(i);
        if ( i >= k ) cout << a[dq.front()] << ' ';
    }

    return 0;
}
