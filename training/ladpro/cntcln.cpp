#include<bits/stdc++.h>
#define ll long long
#define sqr(x) x*x
using namespace std;
const int N = 4e4 + 5;

int n, m, a[N];
ll dp[N];
int last[N];
set<int> diff;

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    dp[0] = 0;
    last[0] = 0;
    diff.insert(0);

    int mx = sqrt(n);

    for (int i = 1; i <= n; i ++){
        dp[i] = i;
        last[i] = INT_MAX;
    }

    for (int i = 1; i <= n; i ++){
        int cnt = 1;

        if ( diff.find(last[a[i]]) != diff.end() ) diff.erase(last[a[i]]);

        for (auto it = diff.rbegin(); it != diff.rend(); ++ it){
            dp[i] = min(dp[i], dp[*it] + sqr(cnt));
            cnt ++;
            if ( cnt > mx ) break;
        }

        last[a[i]] = i;
        diff.insert(i);
    }

    cout << dp[n];

    return 0;
}
