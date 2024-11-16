#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, k;
int a[N], pos[N];
vector<int> cont[N];
vector<pair<int, int>> ans;

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        cont[a[i]].push_back(i);
    }

    pos[1] = *lower_bound(cont[1].begin(), cont[1].end(), 1);
    ans.push_back({pos[1], 1});

    for (int i = 2; i <= k; i ++){
        for (int j = i-1; j >= 0; j --){
            auto it = lower_bound(cont[i].begin(), cont[i].end(), pos[j]);
            if ( it != cont[i].end() ) pos[i] = max(pos[i], *it);
        }
        ans.push_back({pos[i], i});
    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i ++)
        cout << ans[i].second << ' ';

    return 0;
}
