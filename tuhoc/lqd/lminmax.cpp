#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int n;
long long k, a[N];

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    deque<long long> dq_min, dq_max;
    int ans = 1, l = 1;
    for (int i = 1; i <= n; i ++){
        while ( dq_max.size() && a[dq_max.back()] < a[i] ) dq_max.pop_back();
        while ( dq_min.size() && a[dq_min.back()] > a[i] ) dq_min.pop_back();

        dq_max.push_back(i);
        dq_min.push_back(i);

        while ( l < i && dq_max.size() && dq_min.size() && a[dq_max.front()] - a[dq_min.front()] > k ){
            if ( dq_max.front() == l ) dq_max.pop_front();
            if ( dq_min.front() == l ) dq_min.pop_front();
            l ++;
        }

        ans = max(ans, i - l + 1);
    }

    cout << ans;

    return 0;
}
