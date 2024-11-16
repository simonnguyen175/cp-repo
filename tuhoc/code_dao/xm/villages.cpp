#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("villages.inp", "r", stdin); 
    freopen("villages.out", "w", stdout); 

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> cont;
    for (int i = 1, s, t; i <= n; i ++){
        cin >> s >> t;
        if ( s > t ) cont.push_back({t, s});
    }
    long long ans = m;
    sort(cont.begin(), cont.end());
    int l = cont[0].first, r = cont[0].second;
    for (int i = 1; i < (int)cont.size(); i ++){
        if ( cont[i].first >= l && cont[i].first <= r ){
            r = max(r, cont[i].second);
        }
        else{
            ans += 2*(r - l);
//            cout << l << ' ' << r << '\n';
            l = cont[i].first;
            r = cont[i].second;
        }
    }
    ans += 2*(r - l);

    cout << ans;

    return 0;
}
