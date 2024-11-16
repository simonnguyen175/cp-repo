#include<bits/stdc++.h>
#define simon "transet"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int n, s;
vector<int> tran[1005];

namespace sub1{
    void solve(){
        int ans = 0;
        for (int i = 1; i <= n; i ++){
            for (auto v : tran[i]){
                int opt = tran[i].size() + tran[v].size() - 1;
                ans = max(ans, opt);
            }
        }
        cout << ans;
    }
}

namespace sub2{
    void solve(){
        int ans = 0;
        for (int i = 1; i <= n; i ++)
            for (int j = 0; j < tran[i].size(); j ++){
                vector<int> tmp;
                for (int k = 0; k < tran[i].size(); k ++)
                    if ( k != j ) tmp.push_back(tran[i][k]);

                for (int v : tran[j] ) tmp.push_back(v);

                for (auto v : tmp){
                    int opt = tmp.size() + tran[v].size() - 1;
                    ans = max(ans, opt);
                }
            }

        cout << ans;
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++){
        int k; cin >> k;
        for (int j = 1; j <= k; j ++){
            int x; cin >> x;
            tran[i].push_back(x);
        }
    }

    cin >> s;

    if ( s <= 2 ) sub1::solve();
    else if ( s <= 3 ) sub2::solve();

    return 0;
}
