#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;

ll n, a[N], bita[N];
ll diff[N], bitdiff[N], bitdiff1[N];

ll getSum(ll bit[], ll p){
    ll idx = p, ans = 0;
    while ( idx > 0 ){
        ans += bit[idx];
        idx -= idx & (-idx);
    }
    return ans;
}

ll updatePoint(ll bit[], ll u, ll v){
    ll idx = u;
    while ( idx <= n ){
        bit[idx] = v;
        idx += idx & (-idx);
    }
}

void updateRange(ll l, ll r, ll v){
    updatePoint(bitdiff, l, v);
    updatePoint(bitdiff, r + 1, -v);
    updatePoint(bitdiff1, l, (n - l + 1) * v);
    updatePoint(bitdiff1, r + 1, (r - n) * v);
}

ll prefixSum(ll u){
    return getSum(bitdiff1, u) - getSum(bitdiff, u) * ( n - u );
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        diff[i] = a[i] - a[i-1];
        updatePoint(bita, i, a[i]);
        updatePoint(bitdiff, i, diff[i]);
        updatePoint(bitdiff1, i, (n - i + 1) * diff[i]);
    }

    updateRange(1, 3, 3);

    cout << prefixSum(4);

    return 0;
}


