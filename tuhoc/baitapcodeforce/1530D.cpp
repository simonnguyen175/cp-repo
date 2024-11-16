#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int t, n, a[N], b[N];

void solve(){
    unordered_map<int, int> hold;
    deque<int> dq;
    int k = 0;
    for (int i = 1; i <= n; i ++)
        if ( !hold[a[i]] ) b[i] = a[i], hold[a[i]] = i, k ++;
        else b[i] = 0;

    for (int i = 1; i <= n; i ++)
        if ( !hold[i] ) dq.push_back(i);

    for (int i = 1; i <= n; i ++)
        if ( !b[i] )
            if ( i != dq.front() ) b[i] = dq.front(), dq.pop_front();
            else{
                b[i] = dq.front();
                swap(b[i], b[hold[a[i]]]);
                dq.pop_front();
            }

    cout << k << '\n';
    for (int i = 1; i <= n; i ++)
        cout << b[i] << ' ';
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> t;
    while ( t -- ){
        cin >> n;
        for (int i = 1; i <= n; i ++)
            cin >> a[i];
        solve();
    }
    return 0;
}
