#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 2e3 + 5;

int m, n;
int a[N][N];
vector<int> cont[N];
struct area{
    int x, y, u, v;
};
vector<area> ans;

int solve(int L, int R){
    if ( L > R ) return 0;

    for (int i = L; i <= R; i ++) if ( cont[i].size() ){
        int tmp = solve(i+1, R);

        if ( tmp ){
            int cur = 1;
            for (int j = 0; j < cont[i].size(); j ++){
                if ( j == cont[i].size()-1 ) ans.pb({L, cur, i, n});
                else ans.pb({L, cur, i, cont[i][j]});
                cur = cont[i][j] + 1;
            }
        }
        else{
            int cur = 1;
            for (int j = 0; j < cont[i].size(); j ++){
                if ( j == cont[i].size()-1 ) ans.pb({L, cur, R, n});
                else ans.pb({L, cur, R, cont[i][j]});
                cur = cont[i][j] + 1;
            }
        }

        return cont[i].size() + tmp;
    }

    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> m >> n;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++){
        cin >> a[i][j];
        if ( a[i][j] ) cont[i].pb(j);
    }

    cout << solve(1, m) << '\n';

    for (auto it : ans)
        cout << it.x << ' ' << it.y << ' ' << it.u << ' ' << it.v << '\n';

    return 0;
}
