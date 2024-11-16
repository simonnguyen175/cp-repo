#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;

int n, k;
int c[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> c[i];

    ll ans = 0;
    deque<int> dq;
    for (int i = 1; i <= n; i ++){
        while ( dq.size() && c[dq.back()] > c[i] ) dq.pop_back();
        dq.push_back(i);
        while ( dq.front() <= i-k && dq.size() ) dq.pop_front();
        ans += c[dq.front()];
    }

    cout << ans;

    return 0;
}
