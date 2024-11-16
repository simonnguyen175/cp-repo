#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e6 + 5;

int n, l1, l2;
ll ans;
int a[N];
ll f[N];
deque<int> dq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("goldtrace.inp", "r") ){
        freopen("goldtrace.inp", "r", stdin);
        freopen("goldtrace.out", "w", stdout);
    }

    cin >> n >> l1 >> l2;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    int id = 1;
    for (int i = 1; i <= n; i ++){
        while ( i - id >= l1 ){
            while ( dq.size() && f[dq.back()] < f[id] ) dq.pop_back();
            dq.push_back(id);
            id ++;
        }
        while ( dq.size() && i - dq.front() > l2 ) dq.pop_front();

        if ( dq.size() )
            f[i] = f[dq.front()] + a[i];
        else f[i] = a[i];

        if ( ans < f[i] ) ans = f[i];
    }

    cout << ans;

    return 0;
}
