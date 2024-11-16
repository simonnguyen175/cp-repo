#include<bits/stdc++.h>
#define simon "pairwood"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 2e5 + 5;

int n, k, h[N], ans = 0;

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> h[i];
    sort(h + 1, h + 1 + n);

    deque<int> dq;
    dq.push_back(h[1]);

    for (int i = 2; i <= n; i ++){
        if ( dq.empty() ){
            dq.push_back(h[i]);
            continue;
        }
        if ( dq.front() > h[i] ){
            while ( !dq.empty() )
                dq.pop_back();
            dq.push_back(h[i]);
        }
        else{
            dq.pop_front();
            ans ++;
        }
    }

    cout << ans;

    return 0;
}

