#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;

int n, k;
char a[N], b[N];
int pre[2][N], dp[N], f[2][N];

void ckmn(int &a, int b){
    if ( a > b ) a = b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> k;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) cin >> b[i];

    for (int i = 1; i <= n; i ++){
        pre[0][i] = pre[0][i-1];
        pre[1][i] = pre[1][i-1];
        if ( b[i] != b[i-1] )
            if ( b[i] == 'W' ) pre[0][i] ++;
            else pre[1][i] ++;
    }

    deque<int> dqw, dqb;
    dqw.push_back(0);
    dqb.push_back(0);
    for (int i = 1; i <= n; i ++) dp[i] = n + 1;
    f[0][0] = 0;
    f[1][0] = 0;
    dp[0] = 0;


    for (int i = 1; i <= n; i ++){
        if ( a[i] == b[i] ) dp[i] = dp[i-1];
        else{
            /// check white
            while ( dqw.front() < i - k ) dqw.pop_front();
            ckmn(dp[i], f[0][dqw.front()] + pre[0][i] + 1);

            /// check black
            while ( dqb.front() < i - k ) dqb.pop_front();
            ckmn(dp[i], f[1][dqb.front()] + pre[1][i] + 1);
        }

        /// insert in white
        f[0][i] = dp[i] - pre[0][i] + ( b[i] == 'W' && b[i] == b[i+1] );
        while ( dqw.size() && f[0][dqw.back()] > f[0][i] ) dqw.pop_back();
        dqw.push_back(i);

        /// insert in black
        f[1][i] = dp[i] - pre[1][i] + ( b[i] == 'B' && b[i] == b[i+1] );
        while ( dqb.size() && f[1][dqb.back()] > f[1][i] ) dqb.pop_back();
        dqb.push_back(i);
    }

    cout << dp[n] << '\n';

    return 0;
}
