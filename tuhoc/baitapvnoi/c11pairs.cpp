#include<bits/stdc++.h>
using namespace std;

int n;
long long a[500005];
map<long long, int> cnt;
deque<long long> dq;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    long long res = 0;
    bool diff;

    for (int i = 1; i <= n; i ++){
        diff = 1;
        while ( dq.size() && dq.back() <= a[i] ){
            res += cnt[dq.back()];
            if ( dq.back() == a[i] ) diff = 0;
            dq.pop_back();
        }

        if ( dq.size() && dq.back() > a[i] ) res ++;
        if ( diff ) dq.push_back(a[i]), cnt[a[i]] = 1;
        else dq.push_back(a[i]), cnt[dq.back()] ++;
    }

    cout << res;

    return 0;
}
