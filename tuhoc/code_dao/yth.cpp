#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;

ll n, k;
ll a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);

    priority_queue<ll, vector<ll>, greater<ll>> heap;
    ll cur = 0;
    for (int i = 1; i <= n; i ++){
        if ( cur + a[i] <= k ){
            cur += a[i];
            heap.push(a[i]);
        }
        else{
            ll tmp = 0;
            while ( heap.size() && cur - tmp + a[i] > k ){
                tmp += heap.top();
                heap.pop();
            }
            if ( tmp < a[i] ) cur += - tmp + a[i], heap.push(a[i]);
            else heap.push(tmp);
        }
    }

    cout << cur;

    return 0;
}
