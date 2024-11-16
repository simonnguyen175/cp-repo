#include<bits/stdc++.h>
using namespace std;
const int N = 3505;

int n, t, bit1[N];
bitset<N> s[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> t;
    for (int i = 1; i <= n; i ++){
        s[i][i] = 1;
        int u, v;
        cin >> u >> v;
        s[u][v] = s[v][u] = 1;
    }

    for (int i = 1; i <= t; i ++)
    for (int j = 1; j <= n; j ++){
        int u; cin >> u;
        s[j][n+i] = 1 - u;
    }

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
        if ( s[i][j] ){
            for (int k = 1; k <= n; k ++){
                if ( k == i || !s[k][j] ) continue;
                s[k] ^= s[i];
            }
            bit1[i] = j;
            break;
        }

    for (int i = n + 1; i <= n + t; i ++){
        int cnt = 0;
        vector<int> turnon;
        bool check = 1;

        for (int j = 1; j <= n; j ++){
            int pos = bit1[j];
            if ( s[j][i] == 1 && s[j][pos] == 0 ){
                check = 0;
                break;
            }
            if ( s[j][i] == 1 && s[j][pos] == 1 ){
                turnon.push_back(pos);
                cnt ++;
            }
        }

        if ( !check ) cout << -1 << '\n';
        else{
            cout << cnt << ' ';
            for (auto u : turnon) cout << u << ' ';
            cout << '\n';
        }
    }

    return 0;
}
