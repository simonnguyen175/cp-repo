#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;

int trace[905][10005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("spnum.inp", "r") ){
        freopen("spnum.inp", "r", stdin);
        freopen("spnum.out", "w", stdout);
    }

    for (int i = 0; i <= 900; i ++)
    for (int j = 0; j <= 10000; j ++)
        trace[i][j] = -1;

    queue<pi> q;
    q.push({0, 0});
    trace[0][0] = 0;
    while ( q.size() ){
        int s = q.front().fi, p = q.front().se;
        q.pop();

        for (int c = 0; c <= 9; c ++){
            int ns = s + c, np = p + c*c;
            if ( ns > 900 || np > 10000 ) continue;
            if ( trace[ns][np] != -1 ) continue;
            trace[ns][np] = c;
            q.push({ns, np});
        }
    }

    int test;
    cin >> test;
    while ( test -- ){
        int s, p;
        cin >> s >> p;

        if ( s > 900 || trace[s][p] == -1 ) { cout << "No solution\n"; continue; }

        string ans = "";
        while ( s && p ){
            int c = trace[s][p];
            ans += (char) ( '0' + c );
            s -= c;
            p -= c * c;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }

    return 0;
}
